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

void SwapNumbers(int& Num1, int& Num2) {
	int temp;
	temp = Num1;
	Num1 = Num2;
	Num2 = temp;
}

void generateRandomArray(int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		Array[randomNumber(0, 9)] = Array[i];
	}
}

void generateOrderedArray(int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		Array[i] = i + 1;
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

void shuffleArrayElements(int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		SwapNumbers(Array[randomNumber(0, arrayLength - 1)], Array[randomNumber(0, arrayLength - 1)]);
	}
}

int main() {

	srand(time(NULL));

	int Array[100];
	short arrayLength = readNumber("Enter Number Of Elements To Generate Ordered Array Form 1 -> 100 : ");

	generateOrderedArray(Array, arrayLength);

	cout << "Array Before Shuffle : ";
	printArrayElements(Array, arrayLength);

	shuffleArrayElements(Array, arrayLength);
	cout << "Array After Shuffle : ";
	printArrayElements(Array, arrayLength);

	return 0;
}