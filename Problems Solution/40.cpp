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

void copyDistinctNumbers(int originalArray[100], int copyArray[100], short originalArrayLength, short& copyArrayLength) {
	for (int i = 0; i < originalArrayLength; i++) {
		if (!isInArray(originalArray[i],copyArray,copyArrayLength)) {
			addArrayElement(originalArray[i], copyArray, copyArrayLength);
		}
	}
}

int main() {

	srand(time(NULL));

	int Array1[100] = { 10,10,10,50,50,50,70,70,70,90 };
	int Array2[100];

	short array1Length = 10; //Hard Code (;
	short array2Length = 0;

	copyDistinctNumbers(Array1, Array2, array1Length, array2Length);

	cout << "Array1 Elements : ";
	printArrayElements(Array1, array1Length);
	cout << "Array2 Distinct Numbers : ";
	printArrayElements(Array2, array2Length);

	return 0;
}