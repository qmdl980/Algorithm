let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const arr = input[1].split(' ').map(v => +v)
let dp = new Array(arr.length + 1).fill(0)
let answer = []

arr.forEach((item, idx) => {
    dp[idx + 1] = dp[idx] + item
})

input.slice(2).forEach(item => {
    let [x, y] = item.split(' ').map(v => +v)
    answer.push(dp[y] - dp[x - 1])
})

console.log(answer.join('\n'))
