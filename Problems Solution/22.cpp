#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void assignArrayElements(int Array[100], short arrayLength) {
	cout << "Enter Array Elements" << endl;
	cout << "**********************************\n";
	for (int i = 0; i < arrayLength; i++) {
		cout << "Element [" << i + 1 << "] : ";
		cin >> Array[i];
	}
	cout << "**********************************\n";
}

void printArrayElements(int Array[100], short arrayLength) {
	cout << "[ ";
	for (int i = 0; i < arrayLength; i++) {
		cout << Array[i];
		if (!(i == arrayLength - 1)) {
			cout << ", ";
		}
	} 
	cout << " ]" << endl;
}

int countElementFrequency(int Element, int Array[100], short arrayLength) {
	int Counter = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] == Element) {
			Counter++;
		}
	}
	return Counter;
}

void printElementFrequency(int Element, int Array[100], short arrayLength) {
	cout << Element << " is repeated " << countElementFrequency(Element, Array, arrayLength) << " time(s)" << endl;
}

int main() {
	int Array[100];
	short arrayLength = readNumber("Enter Number Of Elements Of Array : ");

	assignArrayElements(Array, arrayLength);
	printArrayElements(Array, arrayLength);
	printElementFrequency(readNumber("Enter Element To Check : "), Array, arrayLength);
	

	return 0;
}