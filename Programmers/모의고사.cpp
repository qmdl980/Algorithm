#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans = {0,0,0};
    vector<int> an1 = {1,2,3,4,5};
    vector<int> an2 = {2,1,2,3,2,4,2,5};
    vector<int> an3 = {3,3,1,1,2,2,4,4,5,5};
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == an1[i%5]){
            ans[0]++;
        }
        if(answers[i] == an2[i%8]){
            ans[1]++;
        }
        if(answers[i] == an3[i%10]){
            ans[2]++;
        }
    }
    for(int i = 0; i < 3; i++){
        if(*max_element(ans.begin(),ans.end()) == ans[i]){
            answer.push_back(i + 1);
        }    
    }
    return answer;
}
