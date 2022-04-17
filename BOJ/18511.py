n, k = map(int, input().split())
arr = list(map(int, input().split()))
answer = 0
arr.sort(reverse=True)


def recur(num, count):
    global answer
    global arr
    if num > n:
        return

    answer = max(answer, num)
    for i in range(k):
        recur(num + count * arr[i], count * 10)


recur(0, 1)
print(answer)
