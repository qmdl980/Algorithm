from collections import deque

def solution(priorities, location):
    answer = 1
    
    for i in range(location):
        if priorities[i] >= priorities[location]:
            answer += 1
    for i in range(location + 1, len(priorities)):
        if priorities[i] >= priorities[location]:
            answer += 1
    
    return answer
