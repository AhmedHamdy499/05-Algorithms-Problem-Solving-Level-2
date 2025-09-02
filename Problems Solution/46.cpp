#include <iostream>
using namespace std;

float myAbs(float Num) {
	if (Num < 0) {
		Num *= -1;
	}
	return Num;
}

int main() {
	float Num;
	cout << "Enter a number :" << endl;
	cin >> Num;

	cout << "My Absolute : " << myAbs(Num) << endl;
	cout << "C++ Absolute : " << abs(Num) << endl;

	return 0;
}