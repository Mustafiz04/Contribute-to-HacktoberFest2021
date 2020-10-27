import pygame
import random
import math
from pygame import mixer

# initialize pygame
pygame.init()

# create the screen
screen = pygame.display.set_mode((800, 600))

# Title and Icon (32x32, png)
pygame.display.set_caption("Space Invaders")
icon = pygame.image.load("ufo.png")
pygame.display.set_icon(icon)

# Background 800x600
background = pygame.image.load("background.png")

# Background Sound
mixer.music.load("background.wav")
mixer.music.play(-1)

# Player - 64x64
playerIMG = pygame.image.load("player.png")
playerX = 368
playerY = 500
playerX_change = 0

# Enemy - 64x64
enemyIMG = []
enemyX = []
enemyY = []
enemyX_change = []
enemyY_change = []
num_of_enemies = 6

for i in range(num_of_enemies):
    enemyIMG.append(pygame.image.load("enemy.png"))
    enemyX.append(random.randint(1, 735))
    enemyY.append(random.randint(50, 150))
    enemyX_change.append(4)
    enemyY_change.append(40)

# Bullet 32x32
# States: v
# ready - bullet not on screen
# fire - bullet is moving
bulletIMG = pygame.image.load("bullet.png")
bulletX = 0
bulletY = 500
bulletY_change = 10
bullet_state = "ready"

# Score
score_value = 0
font = pygame.font.Font('freesansbold.ttf', 32)
textX = 10
textY = 10

# Game Over
over_font = pygame.font.Font('freesansbold.ttf', 64)

def game_over_text():
    over_text = over_font.render("GAME OVER", True, (255, 255, 255))
    screen.blit(over_text, (200, 250))

def show_score(x, y):
    score = font.render("Score: " + str(score_value), True, (255, 255, 255))
    screen.blit(score, (x, y))


def fire_bullet(x, y):
    global bullet_state
    bullet_state = "fire"
    screen.blit(bulletIMG, (x + 16, y + 10))


def player(x, y):
    screen.blit(playerIMG, (x, y))


def enemy(x, y, i):
    screen.blit(enemyIMG[i], (x, y))


def isCollision(enemyX, enemyY, bulletX, bulletY):
    distance = math.sqrt(math.pow(enemyX - bulletX, 2) +
                         math.pow(enemyY - bulletY, 2))
    if distance < 30:
        return True
    else:
        return False


# Game Loop
running = True
while running:

    # RGB - Red, Green, Blue
    screen.fill((0, 0, 0))
    # Background image
    screen.blit(background, (0, 0))

    # Check what is pressed
    for event in pygame.event.get():
        # If X is pressed
        if event.type == pygame.QUIT:
            running = False

        # Right or left or space
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_RIGHT:
                playerX_change = 5
            if event.key == pygame.K_LEFT:
                playerX_change = -5
            if event.key == pygame.K_SPACE:
                if bullet_state == "ready":
                    bullet_sound = mixer.Sound('laser.wav')
                    bullet_sound.play()
                    bulletX = playerX
                    fire_bullet(bulletX, bulletY)

        # TODO - Faulty if 2 are pressed at a time
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_RIGHT or event.key == pygame.K_LEFT:
                playerX_change = 0

    # Player movement
    playerX += playerX_change

    # Check boundaries for player
    if playerX <= 0 or playerX >= 736:
        playerX_change = 0

    # For each enemy
    for i in range(num_of_enemies):
        # Game over
        if enemyY[i] >= 450:
            for j in range(num_of_enemies):
                enemyY[j] = 2000
            game_over_text()
            break

        # Enemy movement
        enemyX[i] += enemyX_change[i]

        if enemyX[i] <= 0 or enemyX[i] >= 736:
            enemyX_change[i] = -(enemyX_change[i])
            enemyY[i] += enemyY_change[i]

        # Collision detection
        collision = isCollision(enemyX[i], enemyY[i], bulletX, bulletY)
        if collision:
            explosion_sound = mixer.Sound('explosion.wav')
            explosion_sound.play()
            bulletY = 500
            bullet_state = "ready"
            score_value += 1
            enemyX[i] = random.randint(1, 735)
            enemyY[i] = random.randint(50, 150)

        # Enemy creation
        enemy(enemyX[i], enemyY[i], i)

    # Bullet movement
    if bulletY <= 0:
        bulletY = 500
        bullet_state = "ready"

    if bullet_state == "fire":
        fire_bullet(bulletX, bulletY)
        bulletY -= bulletY_change

    player(playerX, playerY)

    show_score(textX, textY)

    pygame.display.update()
