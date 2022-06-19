import sys

def input():
    return sys.stdin.readline().rstrip()

"""
n = 1이상 n이하가 되도록 바꿈
k = 자리수
p = 최대 p개를 반전 시킬 수 있음
x = 실제 멈춰 있는 층
"""

def changeLED(n, k, p, x, start):
    global answer
    if k == -1:
        if 1 <= int(x) <= n and x != start:
            answer.add(x)
        return
    for i in range(0, 10):
        if board[int(x[k])][i] <= p:
            a = list(x)
            a[k] = str(i)
            changeLED(n, k - 1, p - board[int(x[k])][i], ''.join(a), start)


n, k, p, x = map(int, input().split())
x = str(x)
if len(x) < k:
    x = '0'*(k-len(x)) + x
answer = set()

board = [[0] * 10 for _ in range(10)]
bit = [0b1111110, 0b0110000, 0b1101101, 0b1111001, 0b0110011, 0b1011011, 0b1011111, 0b1110000, 0b1111111, 0b1111011]
for i in range(10):
    for j in range(10):
        temp = bit[i] ^ bit[j]
        count = 0
        for num in bin(temp):
            if num == '1':
                count += 1
        board[i][j] = count

changeLED(n, k - 1, p, x, x)

print(len(answer))
