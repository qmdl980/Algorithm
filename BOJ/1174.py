import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
arr = []

def bt(cur):
    arr.append(cur)
    for i in range(int(cur[-1])):
        bt(cur + str(i))

if n > 1023:
    print(-1)
else:
    for i in range(10):
        bt(str(i))
    arr.sort(key=lambda x:int(x))
    print(arr[n - 1])
