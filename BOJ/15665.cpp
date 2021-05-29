#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visit[8]{ false };
vector<int> inp;
int ans[8];
int cnt = 0;


void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		inp.push_back(num);
	}
	sort(inp.begin(), inp.end());
}

void solution(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < N; i++) {
		if (!visit[i] && (i == 0 || before != inp[i])) {
			before = inp[i];
			//visit[i] = true;
			ans[depth] = inp[i];
			solution(depth + 1);
			visit[i] = false;
		}
			
	}
}

int main() {
	input();
	solution(0);
}
