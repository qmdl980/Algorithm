import sys

def input():
    return sys.stdin.readline().rstrip()

n, m, r = map(int, input().split())
arr = [list(map(str, input().split())) for _ in range(n)]
commands = list(map(int, input().split()))

def func1(board):
    n, m = len(board), len(board[0])
    temp = [["0"] * m for _ in range(n)]
    for i in range(n):
        temp[i] = arr[n-1-i]
    return temp

def func2(board):
    n, m = len(board), len(board[0])
    temp = [["0"] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            temp[i][j] = board[i][m - 1 - j]
    return temp

def func3(board):
    n, m = len(board), len(board[0])
    temp = [["0"] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            temp[i][j] = board[n - 1 - j][i]
    return temp

def func4(board):
    n, m = len(board), len(board[0])
    temp = [["0"] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            temp[i][j] = board[j][m - 1 - i]
    return temp

def func5(board):
    n, m = len(board), len(board[0])
    temp = [["0"] * m for _ in range(n)]

    for i in range(n//2):
        for j in range(m//2):
            temp[i][m//2 + j] = board[i][j]

    for i in range(n//2):
        for j in range(m//2, m):
            temp[i + n//2][j] = board[i][j]

    for i in range(n//2, n):
        for j in range(m//2, m):
            temp[i][j - m//2] = board[i][j]

    for i in range(n//2, n):
        for j in range(m//2):
            temp[i - n//2][j] = board[i][j]

    return temp

def func6(board):
    n, m = len(board), len(board[0])
    temp = [["0"] * m for _ in range(n)]

    for i in range(n//2):
        for j in range(m//2):
            temp[i + n//2][j] = board[i][j]

    for i in range(n//2):
        for j in range(m//2, m):
            temp[i][j - m//2] = board[i][j]

    for i in range(n//2, n):
        for j in range(m//2, m):
            temp[i - n//2][j] = board[i][j]

    for i in range(n//2, n):
        for j in range(m//2):
            temp[i][j + m//2] = board[i][j]

    return temp


for cmd in commands:
    if cmd == 1:
        arr = func1(arr)
    elif cmd == 2:
        arr = func2(arr)
    elif cmd == 3:
        arr = func3(arr)
    elif cmd == 4:
        arr = func4(arr)
    elif cmd == 5:
        arr = func5(arr)
    elif cmd == 6:
        arr = func6(arr)

for col in arr:
    print(" ".join(col))
