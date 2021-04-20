#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M;
char map[50][50];
int ansCn = 0;
int ansRn = 0;
bool ansR[50]{ };
bool ansC[50]{ };

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < 50; i++) {
		ansR[i] = true;
		ansC[i] = true;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'X') {
				ansR[i] = false;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[j][i] == 'X') {
				ansC[i] = false;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		if (ansC[i]){
			ansCn++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (ansR[i]) {
			ansRn++;
		}
	}
	cout << max(ansCn,ansRn);
}
