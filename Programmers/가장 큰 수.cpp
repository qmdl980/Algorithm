#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    for(int i = 0; i < numbers.size(); i++){
        str.push_back(to_string(numbers[i]));
    }
    
    sort(str.begin(), str.end(), cmp);
    
    for(int i = 0; i < str.size(); i++){
        if(answer != "0"){
            answer = answer + str[i];
        }
    }
    return answer;
}
