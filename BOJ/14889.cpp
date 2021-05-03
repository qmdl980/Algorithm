#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int map[20][20]{};
vector<int> comb1;
vector<int> comb2;
int ans = 100;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	vector<int> v;

	for (int i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	// 0, 1을 넣어 임시 조합 생성
	vector<int> tempVector;

	for (int i = 0; i < N/2; i++)
	{
		tempVector.push_back(1);
	}

	for (int i = 0; i < N/2; i++)
	{
		tempVector.push_back(0);
	}

	sort(tempVector.begin(), tempVector.end());

	//조합을 생성해 2팀을 만듦 (모든 조합 반복작업 해야함)
	do
	{
		for (int i = 0; i < tempVector.size(); i++)
		{
			if (tempVector[i] == 1)
			{ 
				comb1.push_back(v[i]);
			}
			else {
				comb2.push_back(v[i]);
			}
		}
		//팀스코어 매기기
		int stat1 = 0;
		int stat2 = 0;
		for (int i = 0; i < comb1.size(); i++) {
			for (int j = i + 1; j < comb2.size(); j++) {
				stat1 = stat1 + map[comb1[i]][comb1[j]] + map[comb1[j]][comb1[i]];
				stat2 = stat2 + map[comb2[i]][comb2[j]] + map[comb2[j]][comb2[i]];
			}
		}
		//팀 스코어의 가장 작은 차이를 구하기 (ans 출력)
		int tempstat = stat1 - stat2;
		if (tempstat < 0) {
			tempstat = tempstat - (2 * tempstat);
		}
		ans = min(ans, tempstat);
		comb1.clear();
		comb2.clear();
	} while (next_permutation(tempVector.begin(), tempVector.end()));
	
	cout << ans;
}
