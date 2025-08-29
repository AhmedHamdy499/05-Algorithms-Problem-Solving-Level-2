#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void printInReversedOrder(int Num) {
	int Remainder = 0;
	while (Num > 0) {
		Remainder = Num % 10;
		Num /= 10;
		cout << Remainder << endl;
	}
}

int main() {

	printInReversedOrder(readNumber("Please Enter The Number : "));

	return 0;
}