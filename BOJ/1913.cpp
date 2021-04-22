#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, num;
int map[1000][1000]{0};
int ansi, ansj;

int main(void) {
	cin >> N;
	cin >> num;

	map[N / 2][N / 2] = 1;

	for (int i = 0; i < N/2; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 0) {
				for (int k = i; k < N - i - 1; k++) {
					map[k][i] = (N - 2 * i) * (N - 2 * i) - (k - i);
				}
			}
			else if (j == 1) {
				for (int k = i; k < N - i - 1; k++) {
					map[N - 1 - i][k] = (N - 2 * i) * (N - 2 * i) - (N - 1 - 2 * i) - (k - i);
				}
			}
			else if (j == 2) {
				for (int k = i; k < N - i - 1; k++) {
					map[N - 1 - k][N - 1 - i] = (N - 2 * i) * (N - 2 * i) - 2 * (N - 1 - 2 * i) - (k - i);
				}
			}
			else if (j == 3) {
				for (int k = i; k < N - i - 1; k++) {
					map[i][N - 1 - k] = (N - 2 * i) * (N - 2 * i) - 3 * (N - 1 - 2 * i) - (k - i);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
			if (map[i][j] == num) {
				ansi = i + 1;
				ansj = j + 1;
			}
		}
		cout << '\n';
	}
	cout << ansi << " " << ansj;
}
