#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

char question[100][3];
int ret[100][2];
int test_case, cs, cnt;

bool validityCheck(string& str) {
	return str.find_last_of('0') == string::npos	
		&& str.find_last_of(str[0]) == 0	
		&& str.find_last_of(str[1]) == 1;	
}

bool compare(string& str) {
	for (int t = 0; t < test_case; t++) {
		int strikeCnt = 0, ballCnt = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (question[t][i] != str[j])
					continue;

				if (i == j)
					strikeCnt++;
				else
					ballCnt++;

				if (strikeCnt > ret[t][0] || ballCnt > ret[t][1])
					return false;
			}
		}

		if (!(strikeCnt == ret[t][0] && ballCnt == ret[t][1])) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> test_case;

	for (int t = 0; t < test_case; t++)
		cin >> question[t] >> ret[t][0] >> ret[t][1];

	cs = 123;
	while (cs < 1000) {
		auto str = to_string(cs);

		if (validityCheck(str) && compare(str))
			cnt++;
		cs++;
	};
	cout << cnt;
}
