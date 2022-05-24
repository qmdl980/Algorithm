import sys

def input():
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split(' '))
r, c, d = map(int, input().split(' '))
board = [list(map(int, input().split(' '))) for _ in range(n)]
cleaned = [[0] * m for _ in range(n)]
dxy = [[-1, 0], [0, 1], [1, 0], [0, -1]]
answer = 0

while True:
    cleaned[r][c] = 1
    count = 0

    for i in range(4):
        count += 1
        d -= 1
        if d < 0:
            d = 3
        nx = r + dxy[d][0]
        ny = c + dxy[d][1]

        if 0 <= nx < n and 0 <= ny < m:
            if board[nx][ny] == 0 and cleaned[nx][ny] == 0:
                r = nx
                c = ny
                count = 0
                break

    if count == 4:
        nd = d - 2
        nx = r + dxy[nd][0]
        ny = c + dxy[nd][1]
        if 0 <= nx < n and 0 <= ny < m:
            if board[nx][ny] == 1:
                break
            else:
                r = nx
                c = ny

for i in cleaned:
    for j in i:
        if j == 1:
            answer += 1
print(answer)
