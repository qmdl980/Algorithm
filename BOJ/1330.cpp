#include <iostream>
using namespace std;

int main(void) {
	int num, num1;
	cin >> num >> num1;
	if (num > num1) {
		cout << ">";
	}
	else if (num < num1) {
		cout << "<";
	}
	else if (num == num1) {
		cout << "==";
	}
	
}
