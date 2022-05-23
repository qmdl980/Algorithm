import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())

def solution(n):
    if n == 1:
        print(1)
        return
    dp = [0] * n
    dp[0] = 1
    dp[1] = 2

    for i in range(2, n):
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746

    print(dp[n - 1])

solution(n)
