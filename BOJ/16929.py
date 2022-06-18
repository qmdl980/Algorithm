import sys

def input():
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split())
board = [input() for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
answer = "No"

def dfs(start_x, start_y, x, y, count):
    global answer
    if answer == "Yes":
        return
    visited[x][y] = True

    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]
        if 0 <= nx < n and 0 <= ny < m and board[start_x][start_y] == board[nx][ny]:
            if not visited[nx][ny]:
                dfs(start_x, start_y, nx, ny, count + 1)
                visited[nx][ny] = False
            elif nx == start_x and ny == start_y and count > 3:
                answer = "Yes"
                return


for i in range(n):
    if answer == "Yes":
        break
    for j in range(m):
        if answer == "Yes":
            break
        visited[i][j] = True
        dfs(i, j, i, j, 1)
print(answer)
