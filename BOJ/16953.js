let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let [a,b] = input[0].split(' ')

let answer = 1
while(Number(b) > Number(a)){
    if(!(Number(b)%2)){
        b = String(Number(b)/2)
        answer += 1
    }else{
        if(b[b.length-1] == '1') {
            b = b.substring(0, b.length - 1)
            answer += 1
        }
        else{
            answer = -1
            break
        }
    }
}
if(a != b){
    answer = -1
}
console.log(answer)
