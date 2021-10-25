# ------- IMPORTED LIBRARIES ------- #
import numpy as np


# ------- DATA ------- #
data = [
    [3, 1.5, 1],
    [2, 1, 0],
    [4, 1.5, 1],
    [3, 1, 0],
    [3.5, 0.5, 1],
    [2, 0.5, 0],
    [5.5, 1, 1],
    [1, 1, 0]
]


# ------- ACTIVATION FUNCTION ------- #
def sigmoid(x):
    return (1/(1 + np.exp(-x)))


# ------- DERIVATIVE OF ACTIVATION FUNCTION ------- #
def Dsigmoid(x):
    return (sigmoid(x) * (1 - sigmoid(x)))


# ------- DOMAIN OF ACTIVATION FUNCTION ------- #
X = np.linspace(-6, 6, 100)
# ------- RANGE OF ACTIVATION FUNCTION ------- #
Y = sigmoid(X)

# ------- TRAINING ------- #
learningRate = 0.2

# ------- RANDOM INITIAL VALUES ------- #
w1 = np.random.randn()
w2 = np.random.randn()
b = np.random.randn()

for i in range(50000):
    ri = np.random.randint(len(data))

    point = data[ri]
    x = (point[0] * w1) + (point[1] * w2) + b

    prediction = sigmoid(x)
    target = point[2]

    cost = np.square(prediction - target)

    # ------- BACK PROPAGATION ------- #

    # ------- PARTIAL DERIVATIVES ------- #
    Dcost_prediction = 2 * (prediction - target)
    Dprediction_x = Dsigmoid(x)
    Dx_w1 = point[0]
    Dx_w2 = point[1]
    Dx_b = 1

    # ------- CHAIN RULE ON PARTIAL DERIVATIVES ------- #
    Dcost_w1 = Dcost_prediction * Dprediction_x * Dx_w1
    Dcost_w2 = Dcost_prediction * Dprediction_x * Dx_w2
    Dcost_b = Dcost_prediction * Dprediction_x * Dx_b

    # ------- LEARNING ------- #
    w1 = w1 - (learningRate * Dcost_w1)
    w2 = w2 - (learningRate * Dcost_w2)
    b = b - (learningRate * Dcost_b)


# ------- TRAINED MODEL ------- #
length = float(input("\nEnter Length of Flower: "))
width = float(input("\nEnter Width of Flower: "))

x = (length * w1) + (width * w2) + b

prediction = sigmoid(x)

if(prediction > 0.5):
    print("\n\nIt's a Red Flower")
elif(prediction < 0.5):
    print("\n\nIt's a Blue Flower")
else:
    print("\n\nConfused! Something very Rare has happened!!!")