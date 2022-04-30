function solution(land) {
    var answer = 0;
    var dp = land[0]
    
    for(var i = 1; i < land.length; i++){
        let temp = []
        for(var j = 0; j < 4; j++){
            let num = dp[j]
            dp.splice(j,1)
            temp.push(Math.max(...dp) + land[i][j])
            dp.splice(j, 0, num)
        }
        dp = temp
    }
    
    return Math.max(...dp);
}
