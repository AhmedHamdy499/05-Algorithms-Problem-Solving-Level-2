#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void printPattern(int Num) {
	for (int i = 1; i <= Num; i++) {
		for (int j = 1; j <= i; j++) {
			cout << i;
		}
		cout << "\n";
	}
}

int main() {

	printPattern(readNumber("Enter The Number : "));

	return 0;
}