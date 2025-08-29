#include <iostream>
#include <cmath>
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

int main() {

	cout << isPerfect(28) << endl;
	cout << isPerfect(12) << endl;
	cout << isPerfect(6) << endl;

	return 0;
}