import sys

def input():
    return sys.stdin.readline().rstrip()

n, m = map(int, input().split())
know = list(map(int, input().split()))
know.pop(0)
P = [0] * (n + 1)
for i in know:
    P[i] = 1

parties = []
for i in range(m):
    party = list(map(int, input().split()))
    parties.append(party[1:])

for _ in range(m):
    for i in parties:
        for j in i:
            if P[j]:
                for t in i:
                    P[t] = 1
                break

answer = 0
for party in parties:
    flag = 1
    for i in party:
        if P[i]:
            flag = 0
            break
    if flag:
        answer += 1

print(answer)
