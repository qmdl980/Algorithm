import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

k = int(input())
stack = deque([])

for _ in range(k):
    cmd = int(input())
    if cmd:
        stack.append(cmd)
    else:
        if stack:
            stack.pop()

print(sum(stack))
