#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void) {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	vector<int> v = { x, y, w - x, h - y };
	int min = *min_element(v.begin(), v.end());
	cout << min;
}
