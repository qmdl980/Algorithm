import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
arr = [list(map(int, input().split(' '))) for _ in range(n)]
dp = [0] * (n + 1)

cur_max = 0
for i in range(n):
    t, p = arr[i]
    cur_max = max(cur_max, dp[i])

    if i + t < n + 1:
        dp[i + t] = max(dp[i + t], cur_max + p)

print(max(dp))
