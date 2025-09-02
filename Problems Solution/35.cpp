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

bool isInArray(int Num, int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] == Num) {
			return true;
		}
	}
	return false;
}

int getIndex(int Num, int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] == Num) {
			return i;
		}
	}
	return -1;
}

void printResults(int Num, int Array[100], short arrayLength) {
	cout << "Number you looking for is " << Num << endl;
	if (isInArray(Num, Array, arrayLength)) {
		cout << "Yes, The number is found" << endl;
	}
	else {
		cout << "No, The number is not found" << endl;
	}
}

int main() {

	srand(time(NULL));

	int Array[100];
	short arrayLength = readNumber("Enter Number Of Elements To Generate Random Array Form 1 -> 100 : ");

	generateRandomArray(Array, arrayLength);
	printArrayElements(Array, arrayLength);

	int aimedNumber = readNumber("Enter The Number To Search For : ");

	printResults(aimedNumber, Array, arrayLength);

	return 0;
}