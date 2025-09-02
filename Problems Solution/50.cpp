#include <iostream>
using namespace std;

float mySqrt(float Num) {
	if (Num > 0) {
		return pow(Num, 0.5);
	}
	else {
		return -1;
	}
}

int main() {
	float Num;
	cout << "Enter a number :" << endl;
	cin >> Num;

	cout << "My Sqrt : " << mySqrt(Num) << endl;
	cout << "C++ Sqrt : " << sqrt(Num) << endl;


	return 0;
}