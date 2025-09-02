#include <iostream>
using namespace std;

int myRound(float Num) {
	float decimalDigit;
	decimalDigit = Num - (int)Num;
	if (abs(decimalDigit) >= 0.5) {
		if (Num > 0) {
			Num++;
		}
		else {
			Num--;
		}
	}
	return (int)Num;
}

int main() {
	float Num;
	cout << "Enter a number :" << endl;
	cin >> Num;

	cout << "My Round : " << myRound(Num) << endl;
	cout << "C++ Round : " << round(Num) << endl;


	return 0;
}