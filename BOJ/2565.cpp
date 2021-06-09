#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[102] = { 0, };
int ans = 0;

int main() {

	cin >> N;
	int a, b;
	vector<pair<int, int>> v;

	v.push_back({ 0, 0 });
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second&& dp[j] >= dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << N - ans << '\n';
}
