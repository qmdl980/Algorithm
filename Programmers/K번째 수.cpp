#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        vector<int> temp;
        for(int j = commands[i][0]; j <= commands[i][1]; j++){
            temp.push_back(array[j - 1]);
        }
        for(int j = 0; j < temp.size() - 1; j++){
            for(int k = j + 1; k < temp.size(); k++){
                if(temp[j] > temp[k]){
                    int tempn = temp[j];
                    temp[j] = temp[k];
                    temp[k] = tempn;
                }
            }
        }
        answer.push_back(temp[commands[i][2] - 1]);
        temp.clear();
    }
    
    return answer;
}
