import sys, math

def input():
    return sys.stdin.readline().rstrip()

a, b = map(int, input().split())

def func(n):
    result = 0
    num = 1
    while n:
        result += math.ceil(n/2) * num
        n -= math.ceil(n/2)
        num *= 2
    return result

print(func(b) - func(a - 1))
