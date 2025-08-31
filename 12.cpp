#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void printInvertedPattern(int Num) {
	for (int i = Num; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			cout << i;
		}
		cout << "\n";
	}
}

int main() {

	printInvertedPattern(readNumber("Enter The Number : "));

	return 0;
}