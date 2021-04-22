#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string str[1000];

char toChar(int a, int t, int g, int c, int max) {
	if (max == a) return 'A';
	else if (max == c) return 'C';
	else if (max == g) return 'G';
	else return 'T';
}

int main() {
	cin >> N >> M;

	int max1 = 0, hd = 0;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < M; i++) {
		int a = 0, t = 0, g = 0, c = 0;
		for (int j = 0; j < N; j++) {
			switch (str[j][i]) {
			case 'A': a++; break;
			case 'T': t++; break;
			case 'G': g++; break;
			case 'C': c++; break;
			}
		}
		max1 = max(a > c ? a : c, g > t ? g : t);
		hd += (N - max1);
		cout << toChar(a, t, g, c, max1);
	}
	cout << endl << hd;
}
