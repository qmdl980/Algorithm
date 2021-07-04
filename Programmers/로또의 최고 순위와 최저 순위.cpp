#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0;
    int cnt0 = 0;
    vector<int> ans = {6,6,5,4,3,2,1};
    for(int i = 0; i < 6; i++){
        if(lottos[i] == 0){
            cnt0++;
        }else{
            for(int j = 0; j < 6; j++){
                if(lottos[i] == win_nums[j]){
                    cnt++;
                }
            }
        }
        
    }
    answer.push_back(ans[cnt + cnt0]);
    answer.push_back(ans[cnt]);
    return answer;
}
