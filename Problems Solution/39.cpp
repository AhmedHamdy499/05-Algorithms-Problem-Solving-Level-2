#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isPositive(int Num) {
	return Num > 0;
}

bool isPrime(int Num) {
	if (isPositive(Num)) {
		int halfOfNumber = round(Num / 2);
		for (int i = 2; i <= halfOfNumber; i++) {
			if (Num % i == 0) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int randomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

void addArrayElement(int Number, int Array[100], short& arrayLength) {
	arrayLength++;
	Array[arrayLength - 1] = Number;
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

void copyPrimeNumbers(int originalArray[100], int copyArray[100], short originalArrayLength, short& copyArrayLength) {
	for (int i = 0; i < originalArrayLength; i++) {
		if (isPrime(originalArray[i])) {
			addArrayElement(originalArray[i], copyArray, copyArrayLength);
		}
	}
}

int main() {

	srand(time(NULL));

	int Array1[100], Array2[100];

	short array1Length = readNumber("Enter Number Of Elements To Generate Random Array Form 1 -> 100 : ");
	short array2Length = 0;

	generateRandomArray(Array1, array1Length);
	copyPrimeNumbers(Array1, Array2, array1Length, array2Length);

	cout << "Array1 Elements : ";
	printArrayElements(Array1, array1Length);
	cout << "Array2 Prime Numbers : ";
	printArrayElements(Array2, array2Length);

	return 0;
}