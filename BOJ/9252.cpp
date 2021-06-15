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

string A, B;
int dp[1001][1001];
string ans;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> A >> B;
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}

	int i = A.size();
	int j = B.size();
	while (dp[i][j]) {
		int now = dp[i][j];
		if (dp[i - 1][j] == now - 1 && dp[i][j - 1] == now - 1) {
			ans += A[i - 1]; i--; j--;
		}
		else if (dp[i - 1][j] == now - 1 && dp[i][j - 1] == now)j--;
		else if (dp[i - 1][j] == now)i--;
	}
	reverse(ans.begin(), ans.end());

	cout << dp[A.size()][B.size()] << "\n";
	cout << ans << "\n";
}
