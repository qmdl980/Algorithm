import sys

def input():
    return sys.stdin.readline().rstrip()

def solution():
    n = int(input())
    arr = list(map(int, input().split()))
    limit = int(input())
    answer = 0
    if sum(arr) <= limit:
        return max(arr)

    start, end = 0, max(arr)
    while start <= end:
        mid = (start + end) // 2
        total = 0
        for i in arr:
            total += min(mid, i)
        if total > limit:
            end = mid - 1
        else:
            start = mid + 1
            answer = max(answer, mid)
    return answer

print(solution())
