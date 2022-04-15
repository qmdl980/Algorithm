n = int(input())
arr = list(map(int, input().split()))

dp = [0] * n
for i in range(n):
    dp[i] = arr[i]

for i in range(1, n):
    dp[i] = max(dp[i - 1] + arr[i], dp[i])

print(max(dp))
