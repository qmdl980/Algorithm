def solution(numbers, target):
    answer = 0
    tree = [0]
    
    for i in numbers:
        temp = []
        for node in tree:
            temp.append(node + i)
            temp.append(node - i)
        tree = temp
    for node in tree:
        if node == target:
            answer += 1
    
    return answer
