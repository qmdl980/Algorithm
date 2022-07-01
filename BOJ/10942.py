import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
arr = list(map(int, input().split()))
m = int(input())
dp = [[0] * n for _ in range(n)]

for i in reversed(range(n)):
    dp[i][i] = 1
    for j in range(i, n):
        if arr[i] == arr[j]:
            if i + 1 == j or i + 2 == j:
                dp[i][j] = 1
            elif 0 <= i < n - 1 and 0 < j < n:
                if dp[i + 1][j - 1]:
                    dp[i][j] = 1

for _ in range(m):
    s, e = map(int, input().split())
    print(dp[s-1][e-1])
