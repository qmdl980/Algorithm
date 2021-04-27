#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char map[50][50]{};
int candy = 0;
int tempcandy = 0;
int N;

void CandyMax() {
	for (int i = 0; i < N; i++) {
		tempcandy = 1;
		for (int j = 0; j < N; j++) {
			if (map[i][j] == map[i][j + 1]) {
				tempcandy++;
			}
			else {
				candy = max(candy, tempcandy);
				tempcandy = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		tempcandy = 1;
		for (int j = 0; j < N; j++) {
			if (map[j][i] == map[j + 1][i]) {
				tempcandy++;
			}
			else {
				candy = max(candy, tempcandy);
				tempcandy = 1;
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < N; j++) {
			map[i][j] = input[j];
		}
	}

	//행
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] != map[i][j + 1]) {
				swap(map[i][j], map[i][j + 1]);
				CandyMax();
				swap(map[i][j], map[i][j + 1]);
			}
		}
	}

	//열
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (map[j][i] != map[j + 1][i]) {
				swap(map[j][i], map[j + 1][i]);
				CandyMax();
				swap(map[j][i], map[j + 1][i]);
			}
		}
	}
	cout << candy << endl;
}
