import sys

def input():
    return sys.stdin.readline().rstrip()

answer = []
n = int(input())
arr = list(map(int, input().split()))
x_set = list(set(arr))
x_set.sort()
hashmap = {}

for i in range(len(x_set)):
    hashmap[x_set[i]] = i

for i in arr:
    answer.append(str(hashmap[i]))

print(' '.join(answer))
