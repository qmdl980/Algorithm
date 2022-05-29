import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
hi = list(map(int, input().split()))
ai = list(map(int, input().split()))

answer = 0

for i in hi:
    answer += i

ai.sort()
for i in range(n):
    answer += i * ai[i]

print(answer)
