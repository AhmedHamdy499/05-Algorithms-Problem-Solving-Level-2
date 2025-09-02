#include <iostream>
using namespace std;

void printWordsFromAAAtoZZZ() {
	string Word = "";
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			for (int k = 'A'; k <= 'Z'; k++) {
				Word += char(i); Word += char(j); Word += char(k);
				cout << Word << endl;
				Word = "";
			}
		}
	}
}

int main() {

	printWordsFromAAAtoZZZ();

	return 0;
}