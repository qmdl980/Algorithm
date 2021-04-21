#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char map[50][5][7];
int T;
int cnt = 0;
int arr[2];

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 5; j++) {
			string inp;
			cin >> inp;
			for (int k = 0; k < 7; k++) {
				map[i][j][k] = inp[k];
			}
		}
	}
	for (int i = 0; i < T - 1; i++) {
		for (int j = i + 1; j < T; j++) {
			int tempcnt = 0;
			for (int k = 0; k < 5; k++) {
				for (int l = 0; l < 7; l++) {
					if (map[i][k][l] == map[j][k][l]) {
						tempcnt++;
					}
				}
			}
			if (tempcnt == max(cnt, tempcnt)) {
				cnt = tempcnt;
				arr[0] = i + 1;
				arr[1] = j + 1;
			}
		}
	}
	cout << arr[0] << " " << arr[1] << endl;
}
