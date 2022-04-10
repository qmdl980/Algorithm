#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, float> &a, const pair<int, float> &b)
{
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}


vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<float> fail(N, 0);
    vector<float> challenge(N, 0);
    vector<pair<int, float>> p_fail;
    
    for(int i = 0; i < stages.size(); i++){
        if(stages[i] > N){
            for(int j = 0; j < N; j++){
                challenge[j]+=1;
            }
        }else if(stages[i] == 1){
            fail[0]+=1;
            challenge[0]+=1;
        }
        else{
            fail[stages[i]-1]+=1;
            for(int j = stages[i] - 1; j >= 0; j--){
                challenge[j]+=1;
            }
        }
        
    }
    
    for(int i = 0; i < N; i++){
        if(challenge[i] == 0){
            p_fail.push_back(make_pair(i+1, 0));
        }else{
            p_fail.push_back(make_pair(i+1, fail[i]/challenge[i] * 100));
        }
    }
    
    sort(p_fail.begin(),p_fail.end(),cmp);
    
    for(int i = 0; i < N; i++){
        answer.push_back(p_fail[i].first);
    }
    
    
    return answer;
}
