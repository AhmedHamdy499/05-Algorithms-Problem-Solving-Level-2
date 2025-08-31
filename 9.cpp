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

void printAllDigitsFrequency(int Num) {
	for (int Digit = 0; Digit <= 9; Digit++) {
		if (!(countDigitFrequency(Digit, Num) == 0)) {
			cout << "Digit (" << Digit << ") has repeated " << countDigitFrequency(Digit, Num) << " times" << endl;
		}
	}
}

int main() {

	int Num = readNumber("Enter a number : ");

	printAllDigitsFrequency(Num);
	
	return 0;
}