import heapq
import sys


def input():
    return sys.stdin.readline().rstrip()


n = int(input())
arr = []

for i in range(n):
    heapq.heappush(arr, list(map(int, input().split())))

room = [heapq.heappop(arr)[1]]

while arr:
    lecture = heapq.heappop(arr)
    if room[0] <= lecture[0]:
        heapq.heappop(room)
    heapq.heappush(room, lecture[1])

print(len(room))
