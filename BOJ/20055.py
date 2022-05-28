import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, k = map(int, input().split())
conveyer = deque([False] * (n * 2))
a = deque(list(map(int, input().split())))
answer = 1

def rotate():
    conveyer.appendleft(conveyer.pop())
    a.appendleft(a.pop())
    conveyer[n - 1] = False

def move():
    for i in range(n-2, -1, -1):
        if conveyer[i]:
            if not conveyer[i + 1] and a[i + 1] > 0:
                conveyer[i] = False
                conveyer[i + 1] = True
                a[i + 1] -= 1
    conveyer[n - 1] = False

def putRobot():
    global A0
    if a[0] > 0 and not conveyer[0]:
        conveyer[0] = True
        a[0] -= 1

def getA0():
    count = 0
    for i in a:
        if i == 0:
            count += 1
    return count

while True:
    rotate()
    move()
    putRobot()

    if getA0() >= k:
        break
    answer += 1

print(answer)
