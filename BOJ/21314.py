mk = list(input())

max_num = ''
min_num = ''
m_count = 0

for i in range(len(mk)):
    if mk[i] == 'M':
        m_count += 1
        if i == len(mk) - 1:
            max_num += '1' * m_count
            min_num += str(10**(m_count - 1))
    else:
        max_num += str(10**m_count * 5)
        if m_count > 0:
            min_num += str(10**(m_count - 1))
            min_num += '5'
        else:
            min_num += '5'
        m_count = 0


print(max_num)
print(min_num)
