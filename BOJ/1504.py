import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, e = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(e):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

for i in range(n + 1):
    graph[i].sort(key=lambda x: x[1])

v1, v2 = map(int, input().split())


def dijkstra(start):
    global n
    queue = deque([[start, 0]])
    distance = [987654321] * (n + 1)
    distance[start] = 0
    while queue:
        node, dist = queue.popleft()
        if distance[node] < dist:
            continue
        for next, w in graph[node]:
            n_dist = dist + w
            if distance[next] > n_dist:
                queue.append([next, n_dist])
                distance[next] = n_dist

    return distance

root_a = dijkstra(1)[v1]
root_b = dijkstra(1)[v2]

v1v2 = dijkstra(v1)[v2]
root_a += v1v2
root_b += v1v2

root_a += dijkstra(v2)[n]
root_b += dijkstra(v1)[n]

answer = min(root_a, root_b)
if answer >= 987654321:
    print(-1)
else:
    print(answer)
