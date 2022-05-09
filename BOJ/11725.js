let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let n = Number(input[0])
let parent = new Array(n + 1).fill(0)
let graph = new Array()
for(let i = 0; i < n + 1; i++){
    graph.push([])
}
input.slice(1).forEach(item => {
    let [i, j] = item.split(' ').map(v => +v)
    graph[i].push(j)
    graph[j].push(i)
})
parent[1] = 1
let stack = [1]
while(stack.length){
    let node = stack.pop()

    graph[node].forEach(item => {
        if(parent[item] == 0){
            parent[item] = node
            stack.push(item)
        }
    })
}
console.log(parent.slice(2).join('\n'))
