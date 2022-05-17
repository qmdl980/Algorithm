let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

const n = parseInt(input[0])
const paper = input.slice(1).map(v => v.split(' ').map(x => +x))
let answer = [0, 0]

const divide = (x, y, len) => {
    let count = 0
    for(let i = x; i < x + len; i++){
        for(let j = y; j < y + len; j++){
            count += paper[i][j]
        }
    }
    if(count === 0) answer[0]++
    else if(count === len**2) answer[1]++
    else{
        divide(x, y, len/2)
        divide(x, y + len/2, len/2)
        divide(x + len/2, y, len/2)
        divide(x + len/2, y + len/2, len/2)
    }
}
divide(0, 0, n)
console.log(answer.join('\n'))
