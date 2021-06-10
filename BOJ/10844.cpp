#include <cstdio>

using namespace std;

int N;
int dp[101][11] = { 0, };
int ans = 0;

int main() {

	scanf("%d", &N);

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][10] = 0;
		for (int j = 0; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 1; i <= 9; i++) {
		ans = (ans + dp[N][i]) % 1000000000;
	}

	printf("%d\n", ans);

	return 0;
}
