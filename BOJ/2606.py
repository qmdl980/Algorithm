import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
e = int(input())

graph = [[] for i in range(n)]
visited = [False] * n
answer = -1

def DFS(node):
    global answer
    if(visited[node]):
        return
    answer += 1
    visited[node] = True
    for i in range(len(graph[node])):
        DFS(graph[node][i])

for i in range(e):
    v = list(map(int, input().split()))
    graph[v[0] - 1].append(v[1] - 1)
    graph[v[1] - 1].append(v[0] - 1)

DFS(0)

print(answer)
