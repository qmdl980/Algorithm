#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    temp.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        if(temp[temp.size()-1] != nums[i]){
            temp.push_back(nums[i]);
        }
    }
    if(temp.size() >= nums.size()/2){
        answer = nums.size()/2;
    }else{answer = temp.size();}
    return answer;
}
