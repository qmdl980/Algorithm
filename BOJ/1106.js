let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().split('\n')

let c = Number(input[0].split(' ')[0])
let n = Number(input[0].split(' ')[1])
let dp = []
let max_int = 2100000000
let answer = 2100000000

for(let i = 0; i < 1101; i++){
    dp.push(max_int)
}

let arr = []
for(let i = 1; i < input.length; i++){
    let a = Number(input[i].split(' ')[0])
    let b = Number(input[i].split(' ')[1])
    arr.push([a, b])
}

for(let i = 0; i < arr.length; i++){
    for(let j = 1; j < arr[i][1] + 1; j++){
        dp[j] = Math.min(dp[j], arr[i][0])
    }
    for(let j = arr[i][1] + 1; j < 1101; j++){
        dp[j] = Math.min(dp[j], dp[j - arr[i][1]] + arr[i][0])
    }
}

console.log(dp[c])
