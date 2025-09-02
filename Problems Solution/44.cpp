#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isPositive(int Num) {
	return Num > 0;
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

void generateRandomArray(int Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		Array[i] = randomNumber(-100, 100);
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

int countPositiveNumbers(int Array[100], short arrayLength) {
	int Counter = 0;
	for (int i = 0; i < arrayLength; i++) {
		if (isPositive(Array[i])) {
			Counter++;
		}
	}
	return Counter;
}

int main() {

	srand(time(NULL));

	int Array[100];

	short arrayLength = readNumber("Enter Number Of Elements To Generate Random Array Form 1 -> 100 : ");

	generateRandomArray(Array, arrayLength);
	cout << "Array Elements : ";
	printArrayElements(Array, arrayLength);
	cout << "Positive Numbers Count : " << countPositiveNumbers(Array, arrayLength);
	

	return 0;
}