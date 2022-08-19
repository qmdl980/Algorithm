let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().split('\n')

const [n, k] = input[0].split(' ').map(v => +v)
const arr = input[1].split(' ').map(v => +v)
const dp = []
let answer = 0

for(let i = 0; i < k; i++){
    answer += arr[i]
}
dp.push(answer)

let i = 1
while(i < n - k + 1){
    const temp = dp[i - 1] + arr[i + k - 1] - arr[i - 1]
    dp.push(temp)
    answer = Math.max(answer, temp)
    i++
}

console.log(answer)
