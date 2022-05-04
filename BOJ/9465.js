let fs = require('fs')
let input = fs.readFileSync('input.txt').toString().split('\r\n')
//let input = fs.readFileSync('/dev/stdin').toString().split('\n')
let t = Number(input[0])
let answer = []

for(let i = 0; i < t; i++){
    let n = Number(input[1 + (i*3)])
    let arr = []
    arr.push(input[2 + (i*3)].split(' ').map((item) => {return Number(item)}))
    arr.push(input[3 + (i*3)].split(' ').map((item) => {return Number(item)}))
    
    if(n == 1){
        answer.push(Math.max(arr[0][0], arr[1][0]))
        continue
    }

    let dp = []
    let temp = []
    let temp2 = []
    for(let j = 0; j < n; j++){
        temp.push(0)
        temp2.push(0)
    }
    dp.push(temp)
    dp.push(temp2)

    dp[0][0] = arr[0][0]
    dp[1][0] = arr[1][0]
    dp[0][1] = arr[1][0] + arr[0][1]
    dp[1][1] = arr[0][0] + arr[1][1]

    for(let j = 2; j < n; j++){
        dp[0][j] = Math.max(dp[1][j - 1], dp[0][j - 2], dp[1][j - 2]) + arr[0][j]
        dp[1][j] = Math.max(dp[0][j - 1], dp[0][j - 2], dp[1][j - 2]) + arr[1][j]
    }
    answer.push(Math.max(dp[0][n - 1], dp[1][n - 1]))
}
console.log(answer.join('\n'))
