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

void printRandomKeys(int keysCount) {
	for (int i = 1; i <= keysCount; i++) {
		cout << "Key [" << i << "] : " << generateRandomKey(enRandom::CapitalLetter,6,2) << endl;
	}
}

int main() {
	srand(time(NULL));

	printRandomKeys(readNumber("Enter the number of keys : "));

	return 0;
}