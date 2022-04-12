n = int(input())
lope = []
answer = 0

for i in range(n):
    lope.append(int(input()))

lope = sorted(lope, reverse=True)

idx = 0
while True:
    if idx == len(lope):
        break
    answer = max(answer, lope[idx] * (idx + 1))
    idx += 1

print(answer)
