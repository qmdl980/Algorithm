#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int cnt = 0;

int main() {
	cin >> N;
	int tempNum = 665;

	while (1) {
		string temp = to_string(tempNum);

		if (temp.find("666") != -1) {
			cnt++;
		}
		if (cnt == N) {
			cout << temp;
			break;
		}
		tempNum++;
	}
	
}
