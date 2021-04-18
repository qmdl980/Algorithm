#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Hotel {
public:
	int h;
	int w;
	int n;

	Hotel(int _h, int _w, int _n) {
		h = _h;
		w = _w;
		n = _n;
	}
};

int main(void) {
	int count, h, w, n;
	vector<Hotel> v;

	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> h >> w >> n;
		v.push_back(Hotel(h, w, n));
	}
	for (int i = 0; i < count; i++) {
		if (v[i].n % v[i].h == 0) {
			if (v[i].n / v[i].h >= 10) {
				cout << v[i].h << v[i].n / v[i].h << "\n";
			}
			else {
				cout << v[i].h << "0" << v[i].n / v[i].h << "\n";
			}
		}
		else {
			if (v[i].n / v[i].h + 1 >= 10) {
				cout << v[i].n % v[i].h << v[i].n / v[i].h + 1 << "\n";
			}
			else {
				cout << v[i].n % v[i].h << "0" << v[i].n / v[i].h + 1 << "\n";
			}
		}
	}
}
