function operator(a, b, oper){
    if(oper == '+'){ return a + b }
    if(oper == '-'){ return a - b }
    if(oper == '*'){ return a * b }
}

function solution(expression) {
    var answer = []
    var num_arr = []
    var arr = []
    var priority = ['+-*', '+*-', '-+*', '-*+', '*-+', '*+-']
    var temp = ''
    
    for(var i = 0; i < expression.length; i++){
        if(!isNaN(expression[i])){
            temp += expression[i]
        }else{
            num_arr.push(Number(temp))
            arr.push(expression[i])
            temp = ''
        }
        if(i == expression.length - 1){
            num_arr.push(Number(temp))
        }
    }
    
    
    
    for(var i = 0; i < priority.length; i++){
        let temp_num_arr = num_arr.slice()
        let temp_arr = arr.slice()
        
        for(var j = 0; j < 3; j++){
            for(var k = 0; k < temp_arr.length; k++){
                if(temp_arr[k] == priority[i][j]){
                    let a = temp_num_arr[k]
                    let b = temp_num_arr[k + 1]
                    let oper = temp_arr[k]
                    
                    temp_num_arr.splice(k, 2, operator(a, b, oper))
                    temp_arr.splice(k, 1)
                    k--
                }
            }
        }
        answer.push(Math.abs(temp_num_arr[0]))
    }
    
    
    return Math.max(...answer);
}
