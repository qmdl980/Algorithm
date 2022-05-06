import sys

def input():
    return sys.stdin.readline().rstrip()

t = int(input())

for case in range(t):
    n = int(input())
    dict = {}
    for i in range(n):
        clothes, kind = list(input().split())
        if kind in dict:
            dict[kind] += 1
        else:
            dict[kind] = 1

    answer = 1
    for i in dict.items():
        answer *= (i[1] + 1)
    answer -= 1
    print(answer)
