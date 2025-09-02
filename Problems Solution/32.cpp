#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int randomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

void generateRandomArray(int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		Array[i] = randomNumber(1, 100);
	}
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

void copyArrayInReversedOrder(int originalArray[100], int copyArray[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		copyArray[i] = originalArray[arrayLength - 1 - i];
	}
}

int main() {

	srand(time(NULL));

	int Array1[100], Array2[100];
	short arrayLength = readNumber("Enter Number Of Elements To Generate Random Array Form 1 -> 100 : ");

	generateRandomArray(Array1, arrayLength);
	copyArrayInReversedOrder(Array1, Array2, arrayLength);

	cout << "Array1 Elements : ";
	printArrayElements(Array1, arrayLength);
	cout << "Array2 Elements After Copying In Reversed Order : ";
	printArrayElements(Array2, arrayLength);

	return 0;
}