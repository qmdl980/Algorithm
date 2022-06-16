import sys

def input():
    return sys.stdin.readline().rstrip()

S = input()
T = input()
answer = 0

def changeStr(s, t):
    global answer
    if s == t:
        answer = 1
        return
    elif len(s) == len(t):
        return
    else:
        if t[-1] == "A":
            if t[0] == "B":
                changeStr(s, t[1:][::-1])
                changeStr(s, t[:-1])
            else:
                changeStr(s, t[:-1])
        elif t[0] == "B":
            changeStr(s, t[1:][::-1])

changeStr(S, T)
print(answer)
