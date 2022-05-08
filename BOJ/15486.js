let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let n = Number(input[0])
let arr = []
let dp = new Array(n + 1).fill(0)
input.slice(1).forEach(item => {
    const [t, p] = item.split(' ').map(v => +v)
    arr.push([t, p])
})


cur_max = 0
arr.forEach((item, idx) => {
    const [t, p] = item
    cur_max = Math.max(cur_max, dp[idx])
    
    if(idx + t < n + 1){
        dp[idx + t] = Math.max(dp[idx + t], cur_max + p)
    }
})
console.log(Math.max(...dp))
