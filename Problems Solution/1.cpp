#include <iostream>
using namespace std;

void printHeader() {
	cout << "\t\t\t\tMultiplication Table From 1 to 10\t\t\t\t" << endl;
}

void printMultiplierRow() {
	cout << "\t";
	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i;
	}
	cout << "\n";
}

void printHorizontalLine() {
	for (int i = 1; i <= 90; i++) {
		cout << "-";
	}
	cout << "\n";
}

void printRows() {
	for (int Multiplicand = 1; Multiplicand <= 10; Multiplicand++) {
		cout << Multiplicand << "\t|\t";
		for (int Multiplier = 1; Multiplier <= 10; Multiplier++) {
			cout << Multiplicand * Multiplier << "\t";
		}
		cout << "\n";
	}
}

void printMultilplicationTable() {
	printHeader();
	printMultiplierRow();
	printHorizontalLine();
	printRows();
}

int main() {

	printMultilplicationTable();

	return 0;
}