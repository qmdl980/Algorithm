#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int dist(int n, int d){
    vector<vector<int>> map = {{1,2,3},{4,5,6},{7,8,9},{10,0,11}};
    int ni,nj;
    int di,dj;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j ++){
            if(map[i][j] == n){
                ni = i;
                nj = j;
            }
            if(map[i][j] == d){
                di = i;
                dj = j;
            }
        }
    }
    return abs(ni-di) + abs(nj-dj);;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l = 10;
    int r = 11;
    for(int i = 0; i < numbers.size(); i++){
        switch(numbers[i]){
            case 1:
                answer += 'L';
                l = 1;
                break;
            case 4:
                answer += 'L';
                l = 4;
                break;
            case 7:
                answer += 'L';
                l = 7;
                break;
            case 3:
                answer += 'R';
                r = 3;
                break;
            case 6:
                answer += 'R';
                r = 6;
                break;
            case 9:
                answer += 'R';
                r = 9;
                break;
            case 2:
                if(dist(r,2) > dist(l,2)){
                    answer += 'L';
                    l = 2;
                }else if(dist(r,2) < dist(l,2)){
                    answer += 'R';
                    r = 2;
                }else {
                    if(hand == "left"){answer += 'L'; l = 2;}
                    else{answer += 'R'; r = 2;}
                }
                break;
            case 5:
                if(dist(r,5) > dist(l,5)){
                    answer += 'L';
                    l = 5;
                }else if(dist(r,5) < dist(l,5)){
                    answer += 'R';
                    r = 5;
                }else {
                    if(hand == "left"){answer += 'L'; l = 5;}
                    else{answer += 'R'; r = 5;}
                }
                break;
            case 8:
                if(dist(r,8) > dist(l,8)){
                    answer += 'L';
                    l = 8;
                }else if(dist(r,8) < dist(l,8)){
                    answer += 'R';
                    r = 8;
                }else {
                    if(hand == "left"){answer += 'L'; l = 8;}
                    else{answer += 'R'; r = 8;}
                }
                break;
            case 0:
                if(dist(r,0) > dist(l,0)){
                    answer += 'L';
                    l = 0;
                }else if(dist(r,0) < dist(l,0)){
                    answer += 'R';
                    r = 0;
                }else {
                    if(hand == "left"){answer += 'L'; l = 0;}
                    else{answer += 'R'; r = 0;}
                }
                break;
        }
        
    }
    return answer;
}
