import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, k = map(int, input().split())
queue = deque([[n, 0]])
visited = [False] * 100001

while queue:
    x, time = queue.popleft()
    if x == k:
        print(time)
        break
    visited[x] = True
    for nx in [x-1, x+1, x*2]:
        if 0 <= nx <= 100000 and not visited[nx]:
            queue.append([nx, time + 1])
