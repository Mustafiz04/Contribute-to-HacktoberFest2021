import math

def factorial_inbuilt(n):
  return math.factorial(n)

def factorial_recursive(n):
  if n < 2:
    return 1
  else:
    return n * factorial_recursive(n - 1)

def factorial_iterative(n):
  res = 1
  for k in range(2, n + 1):
    res *= k
  return res