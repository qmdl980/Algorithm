import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
answer = 0
temp = {input()}
for i in range(n - 1):
    s = input()
    if s == 'ENTER':
        answer += len(temp) - 1
        temp = {'ENTER'}
    else:
        temp.add(s)

answer += len(temp) - 1
print(answer)
