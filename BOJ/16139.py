import sys

def input():
    return sys.stdin.readline().rstrip()

s = input()
alpha = 'abcdefghijklmnopqrstuvwxyz'
dp = {}

for a in alpha:
    dp[a] = [0] * len(s)

dp[s[0]][0] += 1

for i in range(1, len(s)):
    for j in range(len(alpha)):
        if s[i] == alpha[j]:
            dp[alpha[j]][i] = dp[alpha[j]][i - 1] + 1
        else:
            dp[alpha[j]][i] = dp[alpha[j]][i - 1]

t = int(input())
for _ in range(t):
    a, start, end = input().split()
    start = int(start)
    end = int(end)
    if start == 0:
        print(dp[a][end])
    else:
        print(dp[a][end] - dp[a][start - 1])
