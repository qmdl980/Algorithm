import sys
sys.setrecursionlimit(10**6)

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
graph = [[] for _ in range(n + 1)]

for i in range(n - 1):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])


answer, point = 0, 0
visited = [False] * (n + 1)
def dfs(node, dist):
    global point, answer
    if answer < dist:
        answer = dist
        point = node

    for i in range(len(graph[node])):
        nx, w = graph[node][i]
        if not visited[nx]:
            visited[nx] = True
            dfs(nx, dist + w)

visited[1] = True
dfs(1, 0)
visited = [False] * (n + 1)
visited[point] = True
dfs(point, 0)
print(answer)
