import sys
from collections import deque
def input():
    return sys.stdin.readline().rstrip()

answer = -1
n, m = map(int, input().split())
board = [list(map(int, input())) for _ in range(n)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
dist = [[[0] * 2 for _ in range(m)] for _ in range(n)]

queue = deque([[0, 0, 0]])
dist[0][0][0] = 1
while queue:
    x, y, br = queue.popleft()
    if x == n - 1 and y == m - 1:
        answer = dist[x][y][br]
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if board[nx][ny] and not br:
                dist[nx][ny][1] = dist[x][y][0] + 1
                queue.append([nx, ny, 1])
            elif not board[nx][ny] and not dist[nx][ny][br]:
                dist[nx][ny][br] = dist[x][y][br] + 1
                queue.append([nx, ny, br])

print(answer)
