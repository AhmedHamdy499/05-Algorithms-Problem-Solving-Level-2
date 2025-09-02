#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void printLetterPattern(int Num) {
	char lastChar = 64 + Num;
	for (int i = 'A'; i <= lastChar; i++) {
		for (int j = 1; j <= i - 64; j++) {
			cout << char(i);
		}
		cout << "\n";
	}
}

int main() {

	printLetterPattern(readNumber("Enter The Number : "));

	return 0;
}