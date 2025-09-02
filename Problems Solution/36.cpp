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

bool isLower(char ch) {
	return (ch >= 'a' && ch <= 'z');
}

bool isUpper(char ch) {
	return (ch >= 'A' && ch <= 'Z');
}

bool isLower(string st) {
	for (int i = 0; i < st.length(); i++) {
		if (!isLower(st[i])) {
			return false;
		}
	}
	return true;
}

bool isUpper(string st) {
	for (int i = 0; i < st.length(); i++) {
		if (!isUpper(st[i])) {
			return false;
		}
	}
	return true;
}

string setLower(string st) {
	string Result;
	for (int i = 0; i < st.length(); i++) {
		if (isUpper(st[i])) {
			Result += st[i] + 32;
		}
		else {
			Result += st[i];
		}
	}
	return Result;
}

string setUpper(string st) {
	string Result;
	for (int i = 0; i < st.length(); i++) {
		if (isLower(st[i])) {
			Result += st[i] - 32;
		}
		else {
			Result += st[i];
		}
	}
	return Result;
}

void readArrayElements(int Array[100], short &arrayLength) {
	string userAnswer;
	int i = 0;
	while (true){
		cout << "Enter Number [" << i + 1 << "] : " << endl;
		cin >> Array[i];
		cout << "Do You Want To Add More Numbers ? (Yes/No) " << endl;
		cin >> userAnswer;
		if (setLower(userAnswer) == "no" || userAnswer == "0") {
			break;
		}
		i++;
	}
	arrayLength = i + 1;
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
	short arrayLength;

	readArrayElements(Array, arrayLength);

	cout << "Array Length is " << arrayLength << endl;
	printArrayElements(Array, arrayLength);
	

	return 0;
}