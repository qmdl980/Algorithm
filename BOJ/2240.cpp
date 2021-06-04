#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

int T, W;
int dp[3][1002][32];
int arr[1002];
int ans = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> T >> W;
	for (int i = 1; i <= T; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= W + 1; j++) {
			if (arr[i] == 1) {
				dp[0][i][j] = max(dp[0][i - 1][j] + 1, dp[1][i - 1][j - 1] + 1);
				dp[1][i][j] = max(dp[1][i - 1][j], dp[0][i - 1][j - 1]);
			}
			else if(arr[i] == 2){
				if (i == 1 && j == 1) { continue; }
				dp[0][i][j] = max(dp[1][i - 1][j - 1], dp[0][i - 1][j]);
				dp[1][i][j] = max(dp[0][i - 1][j - 1] + 1, dp[1][i - 1][j] + 1);
			}
		}
	}
	for (int i = 1; i <= W + 1; i++) {
		ans = max(ans, max(dp[0][T][i], dp[1][T][i]));
	}
	cout << ans << '\n';
}
