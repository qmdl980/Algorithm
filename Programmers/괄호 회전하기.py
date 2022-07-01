from collections import deque
def check(s):
    stack = deque([])
    right = [('(',')'),('{','}'),('[',']')]
    for i in s:
        if len(stack):
            if (stack[len(stack) - 1], i) in right:
                stack.pop()
            else:
                stack.append(i)
        else:
            stack.append(i)
                    
    if len(stack):
        return False
    else:
        return True

def solution(s):
    answer = 0
    for i in range(len(s)):
        if check(s[i:] + s[:i]):
            answer += 1

    return answer
