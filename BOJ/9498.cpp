#include <iostream>
using namespace std;

int main(void) {
	int num;
	cin >> num;
	if (num >= 90) {
		cout << "A";
	}
	else if (num <= 89 && num >= 80) {
		cout << "B";
	}
	else if (num <= 79 && num >= 70) {
		cout << "C";
	}
	else if (num <= 69 && num >= 60) {
		cout << "D";
	}
	else {
		cout << "F";
	}
}
