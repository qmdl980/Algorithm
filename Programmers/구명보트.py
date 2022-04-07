from collections import deque

def solution(people, limit):
    answer = 0
    queue = deque(sorted(people))
    
    while queue:
        a = queue.pop()
        if not queue:
            answer += 1
            break
        if a + queue[0] <= limit:
            queue.popleft()
        answer += 1
    
        
    return answer
