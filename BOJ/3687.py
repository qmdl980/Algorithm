import sys

def input():
    return sys.stdin.readline().rstrip()

t = int(input())
num = [0, 0, 1, 7, 4, 2, 0, 8]
dp = [1000000000000000000000] * 101
dp[2], dp[3], dp[4], dp[5], dp[6], dp[7] = 1, 7, 4, 2, 6, 8
for i in range(8, 101):
    for j in range(2, 8):
        dp[i] = min(dp[i], dp[i-j]*10 + num[j])

for _ in range(t):
    n = int(input())
    max_answer = '7' * (n % 2) + '1' * (n // 2 - (n % 2))
    print(dp[n], max_answer)
