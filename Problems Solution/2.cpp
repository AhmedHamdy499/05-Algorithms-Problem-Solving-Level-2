#include <iostream>
using namespace std;

bool isPositive(int Num) {
	return Num > 0;
}

bool isPrime(int Num) {
	if (isPositive(Num)) {
		int halfOfNumber = round(Num / 2);
		for (int i = 2; i <= halfOfNumber; i++) {
			if (Num % i == 0) {
				return false;
			}
		}
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

void printPrimeNumbers(int From, int To) {
	for (int i = From; i <= To; i++) {
		if (isPrime(i)) {
			cout << i << endl;
		}
	}
}

int main() {


	printPrimeNumbers(50, 130);

	return 0;
}