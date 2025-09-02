#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int sumOfDigits(int Num) {
	int Sum = 0, Remainder = 0;
	while (Num > 0) {
		Remainder = Num % 10;
		Num /= 10;
		Sum += Remainder;
	}
	return Sum;
}

int main() {

	cout << sumOfDigits(readNumber("Please Enter The Number : ")) << endl;


	return 0;
}