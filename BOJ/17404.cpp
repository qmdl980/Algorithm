#include <cstdio>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main() {

	int N, i, j;

	int arr[1000][3];
	int dp[1000][3];

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < 3; j++) scanf("%d", &arr[i][j]);

	int ans = 1000002;

	for (int k = 0; k < 3; k++) {
		dp[0][0] = 1000005;
		dp[0][1] = 1000005;
		dp[0][2] = 1000005;
		dp[0][k] = arr[0][k];

		for (i = 1; i < N; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
		}

		
		for (i = 0; i < 3; i++) {
			for (int i = 0; i < 3; i++) {
				if (i == k)continue;
				ans = min(ans, dp[N - 1][i]);
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
