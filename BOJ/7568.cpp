#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<int, int>> v;
int arr[50];
int T;
int weight, height;

int main() {
	for (int i = 0; i < 50; i++) {
		arr[i] = 1;
	}

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> weight >> height;
		v.push_back({ weight, height });
	}
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				arr[i]++;
			}
		}
	}
	for (int i = 0; i < T; i++) {
		cout << arr[i] << " ";
	}
}
