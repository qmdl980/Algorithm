#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

string inp;
vector<char> ans;

int main(void) {
	cin >> inp;

	ans.push_back(inp[0]);

	for (int i = 1; i < inp.size(); i++) {
		if (inp[i] == '-') {
			ans.push_back(inp[i + 1]);
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
}
