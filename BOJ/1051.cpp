#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[50][50]{};

int main() {
	int len = 1;
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < M; j++) {
			map[i][j] = input[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 1; k < min(N, M); k++) {
				if (i + k < N && j + k < M && map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j] && map[i][j] == map[i + k][j + k]) {
					len = max(len, k + 1);
				}
			}
		}
	}
	int square = len * len;
	cout << square;
}
