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

void sumOfTwoArrayElements(int Array1[100], int Array2[100], int sumArray[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		sumArray[i] = Array1[i] + Array2[i];
	}

}

int main() {

	srand(time(NULL));

	int Array1[100], Array2[100], sumArray[100];
	short arrayLength = readNumber("Enter Number Of Elements To Generate Random Array Form 1 -> 100 : ");

	generateRandomArray(Array1, arrayLength);
	generateRandomArray(Array2, arrayLength);
	sumOfTwoArrayElements(Array1, Array2, sumArray, arrayLength);

	cout << "Array1 Elements : ";
	printArrayElements(Array1, arrayLength);

	cout << "Array2 Elements : ";
	printArrayElements(Array2, arrayLength);

	cout << "Sum of 2 Arrays Elements : ";
	printArrayElements(sumArray, arrayLength);

	return 0;
}