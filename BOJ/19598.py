import heapq

n = int(input())
arr = []

for i in range(n):
    a, b = map(int, input().split())
    arr.append([a, b])
arr.sort()

room = [arr[0][1]]

for i in range(1, n):
    if room[0] > arr[i][0]:
        heapq.heappush(room, arr[i][1])
    else:
        heapq.heappop(room)
        heapq.heappush(room, arr[i][1])
    
print(len(room))
