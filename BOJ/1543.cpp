#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string file;
string searchChar;
int cnt = 0;
int correctCnt = 0;

int main() {
	getline(cin, file);
	getline(cin, searchChar);

	if (searchChar.size() > file.size()) {
		cout << 0 << "\n";
	}
	else {
		for (int i = 0; i <= file.size() - searchChar.size(); i++) {
			bool same = true;
			for (int j = 0; j < searchChar.size(); j++) {
				if (file[i + j] != searchChar[j]) {
					same = false;
					break;
				}
			}
			if (same) {
				cnt++;
				i += searchChar.size() - 1;
			}

		}
		cout << cnt << "\n";
	}
}
