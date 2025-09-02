#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enRandom { SmallLetter, CapitalLetter, SpecialCharacter, Digit };

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

int randomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

char Random(enRandom Type) {
	switch (Type) {
	case enRandom::SmallLetter:
	{
		return randomNumber('a', 'z');
	}
	case enRandom::CapitalLetter:
	{
		return randomNumber('A', 'Z');
	}
	case enRandom::SpecialCharacter:
	{
		return randomNumber('!', '/');
	}
	case enRandom::Digit:
	{
		return randomNumber('0', '9');
	}
	default:
	{
		return 0;
	}
	}
}

string generateRandomWord(enRandom wordType, short wordLength) {
	string Word = "";
	for (int i = 1; i <= wordLength; i++) {
		Word += Random(wordType);
	}
	return Word;
}

string generateRandomKey(enRandom Type, short wordsCount, short wordLength, char sperator = '-') {
	string Key = "";
	for (int i = 1; i <= wordsCount; i++) {
		Key += generateRandomWord(Type, wordLength);
		if (!(i == wordsCount)) {
			Key += sperator;
		}
	}
	return Key;
}

void generateKeysArray(string Array[100], short arrayLength) {
	for (int i = 0; i < arrayLength; i++) {
		Array[i] = generateRandomKey(enRandom::CapitalLetter, 4, 4);
	}
}

void printArrayElements(string Array[100], short arrayLength) {
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

	string Array[100];
	short arrayLength = readNumber("Enter Number Of Keys To Generate 1 -> 100 : ");

	generateKeysArray(Array, arrayLength);
	printArrayElements(Array, arrayLength);

	return 0;
}