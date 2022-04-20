n = int(input())
dp = [999999] * 100001


dp[2] = 1
dp[4] = 2
dp[5] = 1
for i in range(6, n + 1):
    dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1)

if dp[n] >= 999999:
    print(-1)
else:
    print(dp[n])
