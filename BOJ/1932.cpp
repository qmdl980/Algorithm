#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int dp[500][500] = { 0, };
int ans = 0;

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &dp[i][j]);
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][0] + dp[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j] + dp[i][j], dp[i - 1][j - 1] + dp[i][j]);
			}
			ans = max(ans, dp[i][j]);
		}
	}

	printf("%d\n", ans);

	return 0;
}
