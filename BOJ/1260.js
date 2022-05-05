let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().split('\n')

let temp = input[0].split(' ')
let [N, M, V] = [Number(temp[0]), Number(temp[1]), Number(temp[2])]
let graph = []
let visited = []
let answer = []

const DFS = (node) => {
    if(visited[node]) return
    
    visited[node] = true
    answer.push(node + 1)

    for(let i = 0; i < graph[node].length; i++){
        DFS(graph[node][i])
    }
}

for(let i = 0; i < N; i++){
    graph.push([])
    visited.push(false)
}

for(let i = 0; i < M; i++){
    temp = input[i + 1].split(' ')
    let [node, edge] = [Number(temp[0]) - 1, Number(temp[1]) - 1]
    graph[node].push(edge)
    graph[edge].push(node)
}

for(let i = 0; i < graph.length; i++){
    graph[i].sort((a, b) => a - b)
}

DFS(V - 1)
answer = [answer.map(item => item)]


for(let i = 0; i < N; i++){
    visited[i] = false
}
let queue = []
let bfs_answer = []
queue.push(V - 1)

while(queue.length != 0){
    
    let node = queue.shift()
    for(let i = 0; i < graph[node].length; i++){
        if(!visited[graph[node][i]]) queue.push(graph[node][i])
    }
    if(visited[node]) continue
    visited[node] = true
    bfs_answer.push(node + 1)
}

answer.push(bfs_answer)

console.log([answer[0].join(' '), answer[1].join(' ')].join('\n'))
