def solution(s):
    answer = [0, 0]
    
    while s != '1':
        answer[0] += 1
        count = 0
        temp = ''
        for i in s:
            if i == '0':
                count += 1
            else:
                temp += i
        answer[1] += count
        s = temp
        s = bin(len(s))[2:]
        
    return answer
