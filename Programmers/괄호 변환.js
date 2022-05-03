const u_and_v = (str) => {
    let open = 0
    let u = ''
    let v = ''
    if(str.length == 0){return str}
    for(let i = 0; i < str.length; i++){
        if(str[i] == '('){ open++ }
        else{ open-- }
        if(open == 0){
            u += str.substr(0, i + 1)
            v += str.substr(i + 1)
            break
        }
    }
    let isValid = true
    let result = ''
    for(let i = 0; i < u.length; i++){
        if(u[i] == '('){ open++ }
        else{
            if(open){open--}
            else{isValid = false}
        }
    }
    if(isValid){
        return u + u_and_v(v)
    }else{
        result += '(' + u_and_v(v) + ')'
        for(let i = 1; i < u.length - 1; i++){
            if(u[i] == '('){result += ')'}
            else{result += '('}
        }
        return result
    }
}

function solution(p) {
    var answer = '';
    let open = 0
    let arr = p.split('')
    //console.log(arr)
    
    if(p.length == 0){ return p }
    //이미 올바른 문자열이면 return
    for(let i = 0; i < p.length; i++){
        if(p[i] == '('){
            open++
        }else{
            if(open){ open-- }
            else{ break }
        }
        if(i == p.length - 1 && open == 0){
            return p
        }
    }
    answer = u_and_v(p)
    
    
    return answer;
}
