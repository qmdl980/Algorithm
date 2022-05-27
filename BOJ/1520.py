import sys
sys.setrecursionlimit(10**6)

def input():
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split(' '))
board = [list(map(int, input().split(' '))) for _ in range(n)]
dp = [[-1] * m for _ in range(n)]
dx = [0, -1, 1, 0]
dy = [1, 0, 0, -1]

def DFS(x, y):
    if x == n - 1 and y == m - 1:
        return 1
    if dp[x][y] != -1:
        return dp[x][y]
    dp[x][y] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if board[nx][ny] < board[x][y]:
                dp[x][y] += DFS(nx, ny)

    return dp[x][y]

print(DFS(0, 0))
