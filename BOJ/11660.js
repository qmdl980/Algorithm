let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const [n, m] = input[0].split(' ').map(v => +v)
const matrix = input.slice(1, n + 1).map(item => {
    return item.split(' ').map(v => +v)
})
let dp = []
for(let i = 0; i < n + 1; i++){
    let temp = []
    for(let j = 0; j < n + 1; j++){
        temp.push(0)
    }
    dp.push(temp)
}

for(let i = 1; i < n + 1; i++){
    for(let j = 1; j < n + 1; j++){
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1]
    }
}
let answer = []
input.slice(n + 1).forEach(item =>{
    const [x1, y1, x2, y2] = item.split(' ').map(v => +v)
    answer.push(dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1])
})

console.log(answer.join('\n'))
