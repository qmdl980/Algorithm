#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
bool visit[8]{ false };
int ans[8];
int cnt = 0;


void input() {
	cin >> N >> M;
}

void solution(int depth) {
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans[depth] = i + 1;
			solution(depth + 1);
			visit[i] = false;
		}
	}
}

int main() {
	input();
	solution(0);
}
