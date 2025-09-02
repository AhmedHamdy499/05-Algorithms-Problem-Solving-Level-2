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

int maxOfArray(int Array[100], short arrayLength) {
	int Max = Array[0];
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] > Max) {
			Max = Array[i];
		}
	}
	return Max;
}

int minOfArray(int Array[100], short arrayLength) {
	int Min = Array[0];
	for (int i = 0; i < arrayLength; i++) {
		if (Array[i] < Min) {
			Min = Array[i];
		}
	}
	return Min;
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

int main() {

	srand(time(NULL));

	int Array[100];
	short arrayLength = readNumber("Enter Number Of Elements To Generate Random Array Form 1 -> 100 : ");

	generateRandomArray(Array, arrayLength);
	printArrayElements(Array, arrayLength);
	cout << "Max Number is " << maxOfArray(Array, arrayLength);


	return 0;
}