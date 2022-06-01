n = int(input())

answer = 0
board = [0] * n

def is_promising(x):
    for i in range(x):
        if board[x] == board[i] or abs(board[x] - board[i]) == x - i:
            return False
    return True

def nQueen(x):
    global answer
    if x == n:
        answer += 1
        return

    for i in range(n):
        board[x] = i
        if is_promising(x):
            nQueen(x + 1)

nQueen(0)
print(answer)
