#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void printInvertedLetterPattern(int Num) {
	char lastChar = 64 + Num;
	for (int i = lastChar; i > 64; i--) {
		for (int j = 1; j <= i - 64; j++) {
			cout << char(i);
		}
		cout << "\n";
	}
}

int main() {

	printInvertedLetterPattern(readNumber("Enter The Number : "));

	return 0;
}