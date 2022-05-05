import sys
sys.setrecursionlimit(10**6)
def input():
    return sys.stdin.readline().rstrip()

t = int(input())

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def DFS(x, y, w, h):
    graph[y][x] = 0
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < w and 0 <= ny < h:
            if(graph[ny][nx] == 1):
                DFS(nx, ny, w, h)


for case in range(t):
    w, h, k = list(map(int, input().split()))
    graph = [[0] * w for _ in range(h)]
    count = 0
    for i in range(k):
        x, y = list(map(int, input().split()))
        graph[y][x] = 1
    for y in range(h):
        for x in range(w):
            if graph[y][x] == 1:
                DFS(x, y, w, h)
                count += 1


    print(count)
