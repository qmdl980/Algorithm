#include <iostream>
#include <vector>
#include<utility>
using namespace std;

int main(void) {
	int a = 1;
	int b = 1;
	vector<pair<int, int>> v;

	while (a || b) {
		cin >> a >> b;
		if (a == 0 && b == 0) {}
		else {
			v.push_back({ a, b });
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first % v[i].second == 0) {
			cout << "multiple\n";
		}
		else if (v[i].second % v[i].first == 0) {
			cout << "factor\n";
		}
		else {
			cout << "neither\n";
		}
	}
}
