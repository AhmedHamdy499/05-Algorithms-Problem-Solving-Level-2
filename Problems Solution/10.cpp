#include <iostream>
#include <cmath>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int integerLength(int Num) {
	int Counter = 0, Remainder = 0;
	while (Num > 0) {
		Num /= 10;
		Counter++;
	}
	return Counter;
}

void printInOrder(int Num) {
	int Length = integerLength(Num);
	int Divisor = pow(10, Length);
	for (int i = 1; i <= Length; i++) {
		Divisor /= 10;
		cout << Num / Divisor << endl;
		Num = Num % Divisor;
	}
}

int main() {

	printInOrder(12003400);

	return 0;
}