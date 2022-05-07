let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().split('\n')

let [n,k] = input[0].split(' ')
let coin = []
for(let i = 1; i < input.length; i++){
    coin.push(Number(input[i]))
}
coin.sort((a,b) => a-b)
let answer = 0
let max = 0

while(k > 0){
    for(let i = 0; i < coin.length; i++){
        if(coin[i] <= k){
            max = coin[i]
        }
    }
    count = Math.floor(k / max)
    k -= max * count
    answer += count
}

console.log(answer)
