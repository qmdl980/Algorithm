#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define MAX 1001
#define MOD 10007

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	int DP[MAX][10] = { 0, };
	int N; cin >> N;

	for (int i = 0; i < 10; i++) DP[0][i] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				DP[i][k] += DP[i - 1][j];
				DP[i][k] %= MOD;
			}
		}
	}

	int sum = 0;

	for (int i = 0; i < 10; i++) sum += DP[N - 1][i];
	cout << sum % MOD;
	return 0;
}
