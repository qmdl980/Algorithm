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

int N, M;
int dp[41];
int ans = 1;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	dp[0] = -1;

	int num;

	for (int i = 1; i <= M; i++) {
		cin >> num;
		dp[num] = -1;
	}

	for (int i = 1; i <= N; i++) {
		if (dp[i] == -1) continue;
		if (dp[i - 1] == -1) {
			dp[i] = 1; continue;
		}
		if (dp[i - 2] == -1 && i > 1) {
			dp[i] = 2; continue;
		}
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	for (int i = 1; i <= N; i++)
		if (dp[i] == -1 && dp[i - 1] != -1)
			ans *= dp[i - 1];

	if (dp[N] != -1) ans *= dp[N];

	cout << ans << '\n';
}
