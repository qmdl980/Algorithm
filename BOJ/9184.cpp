#include <cstdio>
#include <cstring>

using namespace std;

int a,b,c;
int dp[51][51][51];

int w(int x, int y, int z) {
	if (x <= 0 || y <= 0 || z <= 0) {
		return 1;
	}

	int& ans = dp[x][y][z];
	if (ans != -1) return ans;

	if (x > 20 || y > 20 || z > 20) {
		return w(20, 20, 20);
	}
	if (x < y && y < z) {
		return ans = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
	}
	return ans = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
	
}

int main() {

	memset(dp, -1, sizeof(dp));
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) { break; }
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a,b,c));

	}
}
