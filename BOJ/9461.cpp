#include <iostream>

using namespace std;

long long d[100] = { 1,1,1 };

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		for (int i = 3; i <= N; i++) {
			d[i] = d[i - 3] + d[i - 2];
		}
		cout << d[N - 1] << '\n';
	}
}
