import sys

dx = [0, 0, 1, -1]
dy = [-1, 1, 0 , 0]

def input():
    return sys.stdin.readline().rstrip()
n = int(input())
map = [list(map(int, input())) for _ in range(n)]
count = 0
town_count = 0
answer = []


def DFS(x, y):
    global count
    count += 1
    map[x][y] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
            if map[nx][ny] == 1:
                DFS(nx, ny)


for x in range(n):
    for y in range(n):
        if map[x][y] == 1:
            DFS(x, y)
            town_count += 1
            answer.append(count)
            count = 0

answer.sort()
print(town_count)
for i in answer:
    print(i)
