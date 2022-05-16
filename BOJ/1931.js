let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let n = parseInt(input[0])
let arr = []
input.slice(1).forEach(item => {
    arr.push(item.split(' ').map(v => +v))
})

arr.sort((a,b) => {
    return a[1] === b[1] ? a[0] - b[0] : a[1] - b[1]
    
})

let stack = [arr[0]]
arr.slice(1).forEach(item => {
    if(stack[stack.length - 1][1] <= item[0]){
        stack.push(item)
    }
})

console.log(stack.length)
