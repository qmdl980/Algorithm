import sys

def input():
    return sys.stdin.readline().rstrip()

n, m = list(map(int, input().split()))
board = [list(input()) for _ in range(n)]
arr = ['W', 'B']
answer = 2100000000

for x in range(n - 7):
    for y in range(m - 7):
        for case in range(2):
            count = 0
            for i in range(8):
                for j in range(8):
                    if board[x + i][y + j] == arr[(case + i + j) % 2]:
                        count += 1
            answer = min(answer, count)

print(answer)
