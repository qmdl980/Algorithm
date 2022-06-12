import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

n, e = map(int, input().split())
start = int(input())

graph = [[] for _ in range(n + 1)]
distance = [2000000] * (n + 1)

for _ in range(e):
    u, v, w = map(int, input().split())
    graph[u].append([v, w])

queue = [[0, start]]
distance[start] = 0
while queue:
    dist, node = heapq.heappop(queue)
    if distance[node] < dist:
        continue
    for v, w in graph[node]:
        temp = dist + w
        if temp < distance[v]:
            distance[v] = temp
            heapq.heappush(queue, [temp, v])


for i in range(1, n + 1):
    if distance[i] == 2000000:
        print('INF')
    else:
        print(distance[i])
