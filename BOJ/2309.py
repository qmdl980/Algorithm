import itertools
height = []
answer = []

for i in range(9):
    height.append(int(input()))

result = list(itertools.combinations(height, 7))

for i in result:
    if sum(i) == 100:
        answer = sorted(i)

for i in answer:
    print(i)
