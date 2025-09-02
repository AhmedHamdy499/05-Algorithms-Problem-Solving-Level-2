#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int countDigitFrequency(int Digit, int Num) {
	int Counter = 0, Remainder = 0;
	while (Num > 0) {
		Remainder = Num % 10;
		Num /= 10;
		if (Remainder == Digit) {
			Counter += 1;
		}
	}
	return Counter;
}

int main() {

	int Num = readNumber("Enter a number : ");
	int Digit = readNumber("Enter the digit you want to track the number of it's repetitions : ");


	cout << "Digit (" << Digit << ") has repeated " << countDigitFrequency(Digit, Num) << " times" << endl;

	return 0;
}