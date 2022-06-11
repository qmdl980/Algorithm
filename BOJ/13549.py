import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, k = map(int, input().split())
visited = [0] * 100001
queue = deque([n])

while queue:
    
    x = queue.popleft()
    if x == k:
        print(visited[x])
        break

    for nx in [x+1, x-1, x*2]:
        if 0 <= nx < 100001:
            if not visited[nx]:
                if nx == x*2 and nx != 0:
                    visited[nx] = visited[x]
                    queue.appendleft(nx)
                else:
                    visited[nx] = visited[x] + 1
                    queue.append(nx)
