function solution(s) {
    var answer = '';
    var arr = s.split(" ")
    
    for(var i = 0; i < arr.length; i++){
        arr[i] = arr[i].toLowerCase()
        if(isNaN(arr[i][0]) && arr[i] != ''){
            arr[i] = arr[i].replace(arr[i][0], arr[i][0].toUpperCase())
        }
    }
    answer = arr.join(" ")
    
    return answer;
}
