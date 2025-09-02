#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

void addArrayElement(int Number, int Array[100], short& arrayLength) {
	arrayLength++;
	Array[arrayLength - 1] = Number;
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

bool isInArray(int Num, int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] == Num) {
			return true;
		}
	}
	return false;
}

bool isPalindromeArray(int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] != Array[arrayLength - 1 - i]) {
			return false;
		}
	}
	return true;
}

void printResults(int Array[100], short arrayLength) {
	if (isPalindromeArray(Array,arrayLength)) {
		cout << "Yes, it's a palindrome array" << endl;
	}
	else {
		cout << "No, it's not a palindrome array" << endl;
	}
}

int main() {

	int Array[100] = { 10,20,30,40,50,50,40,30,20,10 };
	short arrayLength = 10; //Hard Code (;

	cout << "Array1 Elements : ";
	printArrayElements(Array, arrayLength);
	printResults(Array, arrayLength);
	

	return 0;
}