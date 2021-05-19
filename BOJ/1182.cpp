#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v;
int ans = 0;

void solution(int index, int sum) {
	if (index >= N) {
		return;
	}
	sum += v[index];

	if (sum == S) {
		ans++;
	}
	
	solution(index + 1, sum - v[index]);
	solution(index + 1, sum);
}

int main() {
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	solution(0, 0);
	cout << ans;
}
