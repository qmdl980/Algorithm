def DFS(graph, v):
    if(graph[v][v] == 0):
        return False
    graph[v][v] = 0
    for i in range(len(graph[v])):
        if graph[v][i] :
            graph[v][i] = 0
            DFS(graph, i)
    return True

def solution(n, computers):
    answer = 0
    
    for i in range(n):
        if DFS(computers, i):
            answer += 1
    
    return answer
