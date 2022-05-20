let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let [n,m] = input[0].split(' ').map(item => +item)
let graph = []
let visited = new Array(n + 1).fill(false)

for(let i = 0; i < n + 1; i++){
    graph.push([])
}

input.slice(1).forEach(item => {
    const [no, e] = item.split(' ').map(item => +item)
    graph[no].push(e)
    graph[e].push(no)
})

let answer = 0
//BFS

for(let i = 1; i < n + 1; i++){
    if(!visited[i]){
        queue = [i]
        while(queue.length != 0){
            let node = queue.pop()
            
            if(!visited[node]){
                graph[node].forEach(item => {
                    if(!visited[item]) queue.push(item)
                })
            }
            visited[node] = true
        }
        answer += 1
    }

}
console.log(answer)
