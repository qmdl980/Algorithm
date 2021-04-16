#include <iostream>
using namespace std;

int main(void) {
	int hour, min, time;
	cin >> hour >> min;
	cin >> time;
	min += time;
	if (min >= 60) {
		hour += min / 60;
		if (hour >= 24) {
			hour = hour % 24;
		}
		min = min % 60;
	}
	cout << hour << " " << min;
}
