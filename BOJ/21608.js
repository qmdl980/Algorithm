let fs = require('fs')
let input = fs.readFileSync('input.txt').toString().split('\r\n')
//let input = fs.readFileSync('/dev/stdin').toString().split('\n')

let n = Number(input[0])
let dx = [-1, 0, 0, 1]
let dy = [0, -1, 1, 0]
let sit = []
let like = []
let student_i_like = []
let answer = 0


for(let i = 0; i < n; i++){
    let temp = []
    for(let j = 0; j < n; j++){
        temp.push(0)
    }
    sit.push(temp)
}

for(let i = 0; i < n ** 2 + 1; i++){
    student_i_like.push([])
}

//like에 정보 저장 idx 0 = 학생 번호 idx 1 ~ 4 = 좋아하는 학생 번호
for(let i = 1; i < n ** 2 + 1; i++){
    let arr = input[i].split(' ')
    for(let j = 0; j < arr.length; j++){
        arr[j] = Number(arr[j])
    }
    student_i_like[arr[0]] = arr.slice(1, 5)
    like.push(arr)
}

for(let i = 0; i < like.length; i++){
    //i = like 배열 돌기
    let temp1 = []

    //1번 조건
    let max_like = 0
    for(let j = 0; j < n; j++){
        for(let k = 0; k < n; k++){
            //j, k = map 인덱스
            //칸마다 인접한 칸에 좋아하는 학생이 얼마나 있는지 세기
            let like_count = 0
            for(let l = 0; l < 4; l++){
                if(j + dx[l] >= 0 && k + dy[l] >= 0 && j + dx[l] < n && k + dy[l] < n){
                    for(let like_idx = 1; like_idx < 5; like_idx++){
                        if(sit[j + dx[l]][k + dy[l]] == like[i][like_idx]){
                            like_count++
                            break
                        }
                    }
                }
            }
            
            //지금까지 센거보다 크면 temp(1번조건 만족한 자리)에 자리 x,y값 넣기 같으면 그 칸도 추가
            if(like_count > max_like && sit[j][k] == 0){
                temp1 = [[j, k]]
                max_like = like_count
            }else if(like_count == max_like && sit[j][k] == 0){
                temp1.push([j,k])
            }
        }
    }
    
    if(temp1.length == 1){
        sit[temp1[0][0]][temp1[0][1]] = like[i][0]
    }
    //2번 조건
    else{
        let max_bincan = 0
        let temp2 = []
        for(let j = 0; j < temp1.length; j++){
            //j = 1번 조건 만족한 칸들 리스트 인덱스 temp[i][0] = x temp[i][1] = y
            let count_bincan = 0
            for(let k = 0; k < dx.length; k++){
                //k = dx, dy 인덱스
                if(temp1[j][0] + dx[k] >= 0 && temp1[j][0] + dx[k] < n && temp1[j][1] + dy[k] >= 0 && temp1[j][1] + dy[k] < n){
                    if(sit[temp1[j][0] + dx[k]][temp1[j][1] + dy[k]] == 0){
                        count_bincan++
                    }
                }
            }
            
            if(count_bincan > max_bincan){
                temp2 = [[temp1[j][0], temp1[j][1]]]
                max_bincan = count_bincan
            }else if(count_bincan == max_bincan){
                temp2.push([temp1[j][0], temp1[j][1]])
            }
            
        }
        //console.log(temp2)
        sit[temp2[0][0]][temp2[0][1]] = like[i][0]
    }
}

for(let i = 0; i < n; i++){
    for(let j = 0; j < n; j++){
        //i, j = sit idx sit[i][j] = 학생 번호
        let count = 0
        for(let k = 0; k < 4; k++){
            if(i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < n){
                for(let l = 0; l < 4; l++){
                    if(student_i_like[sit[i][j]][l] == sit[i + dx[k]][j + dy[k]]){
                        count++
                        //console.log(sit[i][j], student_i_like[sit[i][j]], sit[i + dx[k]][j + dy[k]])
                        break
                    }
                }
            }
        }
        if(count == 1){answer += 1}
        else if(count == 2){answer += 10}
        else if(count == 3){answer += 100}
        else if(count == 4){answer += 1000}
    }
}

console.log(answer)
