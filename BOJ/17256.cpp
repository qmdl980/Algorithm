#include <iostream>
using namespace std;

class CakeNum {
public:
	int x;
	int y;
	int z;

	CakeNum(int _x, int _y, int _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	CakeNum operator + (CakeNum& c) {
		x = z + c.x;
		y = y * c.y;
		z = x + c.z;
		return CakeNum(x, y, z);
	}
	CakeNum operator - (CakeNum& c) {
		x = x - c.z;
		y = y / c.y;
		z = z - c.x;
		return CakeNum(x, y, z);
	}
};

int main(void) {
	int num1, num2, num3, num4, num5, num6;
	cin >> num1 >> num2 >> num3;
	cin >> num4 >> num5 >> num6;
	CakeNum cakeNumA = CakeNum(num1, num2, num3);
	CakeNum cakeNumC = CakeNum(num4, num5, num6);
	
	CakeNum cakeNumB = cakeNumC - cakeNumA;
	cout << cakeNumB.x << " " << cakeNumB.y << " " << cakeNumB.z;

	return 0;
}
