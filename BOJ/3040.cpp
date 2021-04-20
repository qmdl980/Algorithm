#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void) {
	vector<int> inputV(9);
	for (int i = 0; i < 9; i++) {
		cin >> inputV[i];
	}
	int sum = 0;

	for (auto i = inputV.begin(); i != inputV.end(); i++) {
		sum += *i;
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - inputV[i] - inputV[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k != i && k != j) {
						cout << inputV[k] << "\n";
					}
				}
				break;
			}
		}
	}
}
