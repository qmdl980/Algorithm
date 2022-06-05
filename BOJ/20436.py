import sys

def input():
    return sys.stdin.readline().rstrip()

def word_idx(word):
    for i in range(3):
        if word in keyboard[i]:
            return [i, keyboard[i].index(word)]

left, right = input().split()
ans = input()
keyboard = ['qwertyuiop','asdfghjkl','zxcvbnm']
xy_l = word_idx(left)
xy_r = word_idx(right)

answer = 0
for word in ans:
    xy = word_idx(word)
    if word in 'qwertasdfgzxcv':
        answer += abs(xy_l[0] - xy[0]) + abs(xy_l[1] - xy[1])
        xy_l = xy
    else:
        answer += abs(xy_r[0] - xy[0]) + abs(xy_r[1] - xy[1])
        xy_r = xy
    answer += 1

print(answer)
