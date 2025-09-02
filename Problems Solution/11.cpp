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

bool isPalindrome(int Num) {
	return reverseNumber(Num) == Num;
}

int main() {

	cout << isPalindrome(12345) << endl; // ===> 0
	cout << isPalindrome(12321) << endl; // ===> 1
	cout << isPalindrome(2552) << endl;  // ===> 1
	cout << isPalindrome(1212) << endl;  // ===> 0
	cout << isPalindrome(2112) << endl;  // ===> 1

	return 0;
}