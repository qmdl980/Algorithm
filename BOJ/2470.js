let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().split('\n')

let n = Number(input[0])
let temp = input[1].split(' ')
let arr = []
let acid = 2000000001
let answer = []

for(let i = 0; i < n; i++){
    arr.push(Number(temp[i]))
}
let left = 0
let right = n - 1
arr.sort((a, b) => {return a-b})

while(left < right){
    let temp = arr[left] + arr[right]
    
    if(Math.abs(temp) < acid){
        answer = [arr[left], arr[right]]
        acid = Math.abs(temp)
        if(temp == 0) break   
    }
    if(temp < 0){
        left++
    }else{
        right--
    }
}

console.log(answer.join(' '))
