import sys
import math

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
arr = list(map(int, input().split()))
operator = list(map(int, input().split()))
answer = [-1000000000, 1000000000]

def recur(num, idx, oper):
    if idx == n:
        answer[0] = max(num, answer[0])
        answer[1] = min(num, answer[1])
        return
    if oper[0]:
        oper[0] -= 1
        recur(num + arr[idx], idx + 1, oper)
        oper[0] += 1
    if oper[1]:
        oper[1] -= 1
        recur(num - arr[idx], idx + 1, oper)
        oper[1] += 1
    if oper[2]:
        oper[2] -= 1
        recur(num * arr[idx], idx + 1, oper)
        oper[2] += 1
    if oper[3]:
        oper[3] -= 1
        recur(math.trunc(num / arr[idx]), idx + 1, oper)
        oper[3] += 1

recur(arr[0], 1, operator)
print(answer[0])
print(answer[1])
