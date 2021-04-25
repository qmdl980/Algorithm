#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int main(void) {
	int num;
	vector<int> a;
	
	for (int i = 0; i < 5; i++) {
		cin >> num;
		a.push_back(num);
	}
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				for (int j = 0; j < 5; j++) {
					cout << a[j] << " ";
				}
				cout << "\n";
			}
		}
		for (int i = 0; i < 5; i++) {
			if (a[i] == i + 1) {
				cnt++;
			}
		}
		if (cnt == 5) {
			break;
		}
	}
}
