import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
deq = deque([])

for i in range(n):
    cmd = input().split()
    if cmd[0] == 'push_front':
        deq.appendleft(cmd[1])
    elif cmd[0] == 'push_back':
        deq.append(cmd[1])
    elif cmd[0] == 'pop_front':
        if len(deq):
            print(deq.popleft())
        else:
            print(-1)
    elif cmd[0] == 'pop_back':
        if len(deq):
            print(deq.pop())
        else:
            print(-1)
    elif cmd[0] == 'size':
        print(len(deq))
    elif cmd[0] == 'empty':
        if len(deq):
            print(0)
        else:
            print(1)
    elif cmd[0] == 'front':
        if len(deq):
            print(deq[0])
        else:
            print(-1)
    elif cmd[0] == 'back':
        if len(deq):
            print(deq[len(deq) - 1])
        else:
            print(-1)
