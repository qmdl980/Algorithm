import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, w, l = map(int, input().split())
truck = deque(list(map(int, input().split())))

bridge = deque([0] * w)
answer = 0

while bridge:
    answer += 1
    bridge.popleft()
    if truck:
        if sum(bridge) + truck[0] <= l:
            bridge.append(truck.popleft())
        else:
            bridge.append(0)

print(answer)
