#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N;
int ran;
int line[10];

int main(void) {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> ran;
		for (int j = 0; j < N; j++)
			if (ran == 0 && line[j] == 0) {
				line[j] = i + 1;
				break;
			}
			else if (line[j] == 0) {
				ran--;
			}
	}

	for (int i = 0; i < N; i++) {
		cout << line[i] << " ";
	}

}
