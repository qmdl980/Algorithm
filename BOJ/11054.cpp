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

int N;
int dp[1001];
int dp2[1001];
int arr[1001];
int ans = 0;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = N - 1; j > i; j--)
		{
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
			{
				dp2[i] = dp2[j] + 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i] + dp2[i]);
	}
	cout << ans - 1 << '\n';
}
