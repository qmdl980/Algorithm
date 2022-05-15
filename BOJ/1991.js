let fs = require('fs')
//let input = fs.readFileSync('input.txt').toString().trim().split('\r\n')
let input = fs.readFileSync('/dev/stdin').toString().trim().split('\n')

let n = Number(input[0])
let tree = {}
let answer = ['','','']
input.slice(1).forEach(item => {
    let temp = item.split(' ')
    tree[item[0]] = temp.slice(1)
})

//전위
function preorder(node){
    if(node == '.') return
    const [left, right] = tree[node]
    answer[0] += node
    preorder(left)
    preorder(right)
}

function inorder(node){
    if(node == '.') return
    const [left, right] = tree[node]
    inorder(left)
    answer[1] += node
    inorder(right)
}

function postorder(node){
    if(node == '.') return
    const [left, right] = tree[node]
    postorder(left)
    postorder(right)
    answer[2] += node
}

preorder('A')
inorder('A')
postorder('A')

console.log(answer.join('\n'))
