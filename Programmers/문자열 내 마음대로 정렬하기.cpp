#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	
	for (int i = 0; i < strings.size() - 1; i++) {
		for (int j = i + 1; j < strings.size(); j++) {
			if (strings[i][n] > strings[j][n]) {
				swap(strings[i], strings[j]);
			}
			if (strings[i][n] == strings[j][n]) {
				if (strings[i] > strings[j]) {
					swap(strings[i], strings[j]);
				}
			}
		}
	}
	vector<string> answer = strings;
	return answer;
}
