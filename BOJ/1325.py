import sys
from collections import deque

def input():
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]
answer = []
maxc = 0

for i in range(m):
    v, e = map(int, input().split())
    graph[e].append(v)

for i in range(1, n + 1):
    queue = deque([i])
    visited = [False for _ in range(n + 1)]
    count = 0
    while len(queue):
        node = queue.pop()
        if visited[node]:
            continue
        visited[node] = True
        count += 1
        for j in range(len(graph[node])):
            queue.append(graph[node][j])
    if count > maxc:
        maxc = count
        answer = [str(i)]
    elif count == maxc:
        answer.append(str(i))

print(" ".join(answer))
