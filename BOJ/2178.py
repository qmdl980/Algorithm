import sys

def input():
    return sys.stdin.readline().rstrip()

n, m = list(map(int, input().split()))
graph = [list(map(int, input())) for _ in range(n)]
dist = [[False] * m for _ in range(n)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

queue = [(0, 0)]
dist[0][0] = 1

while queue:
    x, y = queue.pop(0)

    if x == n - 1 and y == m - 1:
        print(dist[x][y])
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if dist[nx][ny] == 0 and graph[nx][ny] == 1:
                dist[nx][ny] = dist[x][y] + 1
                queue.append((nx, ny))
