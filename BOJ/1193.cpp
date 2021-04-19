#include <iostream>
using namespace std;


int main(void) {
	int x;
	cin >> x;
	int n = 0;
	int a, b;

	int sum = 0;
	int arr[4500];
	for (int i = 0; i < 4500; i++) {
		sum += i;
		arr[i] = sum;
	}
	for (int i = 0; i < 4500; i++) {
		if (x > arr[i]) {
			n = i + 1;
		}
	}
	if (n % 2 == 0) {
		a = 1;
		b = n;
		for (int i = 1; i < x - arr[n - 1]; i++) {
			a++;
			b--;
		}
		cout << a << "/" << b << "\n";
	}
	else {
		a = n;
		b = 1;
		for (int i = 1; i < x - arr[n - 1]; i++) {
			a--;
			b++;
		}
		cout << a << "/" << b << "\n";
	}
	
}
