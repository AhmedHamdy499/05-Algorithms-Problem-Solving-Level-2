#include <iostream>
using namespace std;

bool isInteger(float Num) {
	float decimalDigit = Num - (int)Num;
	return decimalDigit == 0;
}

int myFloor(float Num) {
	if (Num < 0 && !(isInteger(Num))) {
			Num--;
	}
	return (int)Num;
}

int main() {
	float Num;
	cout << "Enter a number :" << endl;
	cin >> Num;

	cout << "My Floor : " << myFloor(Num) << endl;
	cout << "C++ Floor : " << floor(Num) << endl;


	return 0;
}