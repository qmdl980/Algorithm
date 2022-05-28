import sys

def input():
    return sys.stdin.readline().rstrip()

n, m, k = map(int, input().split())
dxy = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
board = [[[] for _ in range(n)] for _ in range(n)]
fireballs = []

for i in range(m):
    x, y, m, s, d = map(int, input().split())
    fireballs.append([x-1, y-1, m, s, d])

for _ in range(k):

    while fireballs:
        x, y, m, s, d = fireballs.pop()
        nx = (x + dxy[d][0] * s) % n
        ny = (y + dxy[d][1] * s) % n
        board[nx][ny].append([m, s, d])

    for i in range(n):
        for j in range(n):
            if len(board[i][j]) > 1:
                sum_m, sum_s, odd, even, cnt = 0, 0, 0, 0, len(board[i][j])
                while board[i][j]:
                    m, s, d = board[i][j].pop()
                    sum_m += m
                    sum_s += s
                    if d % 2:
                        odd += 1
                    else:
                        even += 1
                if odd == cnt or even == cnt:
                    nd = [0, 2, 4, 6]
                else:
                    nd = [1, 3, 5, 7]
                if sum_m//5:
                    for d in nd:
                        fireballs.append([i, j, sum_m//5, sum_s//cnt, d])
            if len(board[i][j]) == 1:
                fireballs.append([i, j] + board[i][j].pop())

answer = 0
for x, y, m, s, d in fireballs:
    answer += m

print(answer)
