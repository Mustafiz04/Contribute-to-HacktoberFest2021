#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x,y,fruitX,fruitY,score;
int tailX[100], tailY[100];
int nTail;

enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	fruitX = rand()%width;
	fruitY = rand()%height;
	score = 0;
}
void Draw()
{
	system("cls");
	for(int i=0;i<width+2;i++)//upper wall
	    cout<<"_";
	cout << endl;
	
	for(int i=0;i<height;i++)//side walls
	{
		for(int j=0;j<width;j++)
		{
			if(j == 0)
			    cout<<"|";
			if ( i == y && j == x)
				cout<<"@";
			else if (i == fruitY && j == fruitX)
				cout<<"8";
			else       //making the tail. 
			{
				bool print = false;
				for(int k = 0;k < nTail; k++)
				{
					if(tailX[k] == j && tailY[k] == i)
					{
						cout<<"+";
						print = true;
					}	
				}
			
			    if (!print)
				    cout <<" ";	
			}
			
			if(j == width-1)//side wall (right)
			    cout<<"|";
		}
		cout<<endl;
	}
	
	for(int i = 0;i<width+2;i++)
	    cout<<"-";//lower wall
	cout<<endl;
	cout<<"Score : "<<score<<endl;
}
void Input()
{
	if(kbhit())// inputs to move the snake.
	{
		switch (_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case ' ':
				gameOver = true;
				break;
				
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY [i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;	
	}
	switch(dir)
	{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;			
	}
	if(x > width || x < 0 ||y > height || y<0) // if the snake touches the boundaries then the game is over.
	    gameOver = true;
	for(int i = 0;i < nTail; i++)
	{
		if(tailX[i] == x && tailY[i] == y) // if the snake touches itself then the game is over.
			gameOver = true;
	}
	if(x == fruitX && y == fruitY)//if the snake eats the fruit, the score increases by 10.
	{
		score += 10; 
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
/*     o o o o o    @ o o o o o o o
       o 
       o
       @
 */     
int main() 
{
    	Setup();
    	while(!gameOver)
    	{
    		Draw();
    		Input();
    		Logic();
    		Sleep(20);
		}
		if(gameOver)cout<<"Total Score = "<<score<<endl;
    return 0;
}
