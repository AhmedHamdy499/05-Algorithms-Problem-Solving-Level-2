#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int reverseNumber(int Num) {
	int reversedNumber = 0, Remainder = 0;
	while (Num > 0) {
		Remainder = Num % 10;
		Num /= 10;
		reversedNumber = reversedNumber * 10 + Remainder;
	}
	return reversedNumber;
}

int main() {

	cout << reverseNumber(readNumber("Please Enter The Number : ")) << endl;

	return 0;
}