let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let a = input[0].split('')
let b = input[1].split('')
let dp = []
for(let i = 0; i < a.length + 1; i++){
    let temp = []
    for(let j = 0; j < b.length + 1; j++){
        temp.push(0)
    }
    dp.push(temp)
}
for(let i = 1; i < a.length + 1; i++){
    for(let j = 1; j < b.length + 1; j++){
        if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1
        else dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
    }
}

console.log(dp[a.length][b.length])
