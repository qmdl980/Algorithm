#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int map[12][12]{};
bool visit[12][12]{};
int minVal = 2123456789;

void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			map[i][j] = 0;
			visit[i][j] = false;
		}
	}
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
}
bool check(int x, int y) {

	if (x + 1 < N && x - 1 >= 0 && y - 1 >= 0 && y + 1 < N) {

		if (visit[x][y] == 0 && visit[x + 1][y] == 0 && visit[x - 1][y] == 0 && visit[x][y + 1] == 0 && visit[x][y - 1] == 0) {

			return true;

		}

	}

	return false;

}

void dfs(int depth, int x, int y, int sum) {

	if (depth == 3) {
		minVal = min(minVal, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check(i, j)) {
				visit[i][j] = visit[i + 1][j] = visit[i - 1][j] = visit[i][j + 1] = visit[i][j - 1] = 1;
				sum = sum + map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1] + map[i][j - 1];

				dfs(depth + 1, i, j, sum);

				visit[i][j] = visit[i + 1][j] = visit[i - 1][j] = visit[i][j + 1] = visit[i][j - 1] = 0;
				sum = sum - map[i][j] - map[i + 1][j] - map[i - 1][j] - map[i][j + 1] - map[i][j - 1];
			}
		}
	}
}


int main() {
	init();
	input();
	dfs(0,0,0,0);
	cout << minVal << endl;
}
