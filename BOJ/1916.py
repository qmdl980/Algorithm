import sys
import heapq
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
m = int(input())
graph = {}

for _ in range(m):
    a, b, c = map(int, input().split())
    if a in graph:
        heapq.heappush(graph[a], [c, b])
    else:
        graph[a] = [[c, b]]

MAX = 100000000
distance = [MAX + 1] * (n + 1)
start, end = map(int, input().split())
queue = deque([start])
distance[start] = 0

while queue:
    x = queue.popleft()
    if x in graph:
        for w, nx in graph[x]:
            if distance[nx] > MAX or distance[x] + w < distance[nx]:
                queue.append(nx)
                distance[nx] = distance[x] + w

print(distance[end])
