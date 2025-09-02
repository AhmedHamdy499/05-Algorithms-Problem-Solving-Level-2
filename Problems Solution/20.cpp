#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enRandom { SmallLetter, CapitalLetter, SpecialCharacter, Digit };

int randomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

char Random(enRandom Type) {
	switch (Type) {
		case enRandom::SmallLetter: 
		{
			return randomNumber('a','z');
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

int main() {
	srand(time(NULL));

	cout << Random(enRandom::SmallLetter) << endl;
	cout << Random(enRandom::CapitalLetter) << endl;
	cout << Random(enRandom::SpecialCharacter) << endl;
	cout << Random(enRandom::Digit) << endl;

	return 0;
}