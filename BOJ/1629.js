let fs = require('fs')
let [a, b, c] = fs.readFileSync('/dev/stdin').toString().trim().split(' ').map(BigInt)

const pow = (a, b) => {
    if(b == 0) return BigInt(1)
    else{
        const temp = pow(a, BigInt(parseInt(b / BigInt(2))))
        if(b%BigInt(2) == 1){
            return (temp * temp * a) % c
        }
        else{
            return (temp * temp) % c
        }
    }
}

console.log(parseInt(pow(a, b)))
