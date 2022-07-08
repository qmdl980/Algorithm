import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

def solution(n, k):
    dist = [-1] * 100001
    queue = deque([n])
    dist[n] = 0
    flag = 1000000
    count = 0
    while queue:
        x = queue.popleft()
        if flag < dist[x]:
            break
        if x == k:
            if flag == dist[x]:
                count += 1
            else:
                flag = dist[x]
                count = 1
        for nx in [x - 1, x + 1, 2 * x]:
            if 0 <= nx <= 100000 and (dist[nx] == -1 or dist[x] + 1 == dist[nx]):
                queue.append(nx)
                dist[nx] = dist[x] + 1
    return [str(dist[k]), str(count)]


n, k = map(int, input().split())
print("\n".join(solution(n, k)))
