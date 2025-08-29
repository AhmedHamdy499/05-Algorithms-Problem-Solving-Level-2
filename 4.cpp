#include <iostream>
using namespace std;

int sumOfDivisors(int Num) {
	int Sum = 0;
	int halfOfNumber = round(Num / 2);
	for (int i = 1; i <= halfOfNumber; i++) {
		if (Num % i == 0) { // i is divisor
			Sum += i;
		}
	}
	return Sum;
}

bool isPerfect(int Num) {
	if (sumOfDivisors(Num) == Num) {
		return true;
	}
	else {
		return false;
	}

}

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void printPerfectNumbers(int From, int To) {
	for (int i = From; i <= To; i++) {
		if (isPerfect(i)) {
			cout << i << endl;
		}
	}
}

int main() {

	printPerfectNumbers(1, readNumber("Please Enter The Number : "));

	return 0;
}