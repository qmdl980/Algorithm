n = int(input())
answer = [[' '] * 2 * n for _ in range(n)]

def recur(x, y, n):
    if n == 3:
        answer[x][y] = '*'
        answer[x+1][y-1] = answer[x+1][y+1] = '*'
        for i in range(-2, 3):
            answer[x+2][y+i] = '*'
    else:
        next_n = n // 2
        recur(x, y, next_n)
        recur(x+next_n, y-next_n, next_n)
        recur(x+next_n, y+next_n, next_n)

recur(0, n-1, n)

for row in answer:
    print("".join(row))
