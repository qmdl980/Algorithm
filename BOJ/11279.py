import heapq
import sys

def input():
    return sys.stdin.readline().rstrip()

n = int(input())
heap = []

for i in range(n):
    num = int(input())
    if num == 0:
        if len(heap):
            print(-heapq.heappop(heap))
        else:
            print(0)
    else:
        heapq.heappush(heap, -num)
