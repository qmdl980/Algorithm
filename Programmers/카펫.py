def solution(brown, yellow):
    answer = []
    x = int((brown - 2) / 2)
    y = 3
    while True:
        if yellow == (x-2) * (y-2):
            answer.append(x)
            answer.append(y)
            break
        else:
            x -= 1
            y += 1
        
    return answer
