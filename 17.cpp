#include <iostream>
using namespace std;

string readText(string Message) {
	string Text;
	cout << Message << endl;
	cin >> Text;
	return Text;
}

bool guessPassword(string Password) {
	string Word = "";
	int Trials = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		for (int j = 'A'; j <= 'Z'; j++) {
			for (int k = 'A'; k <= 'Z'; k++) {
				Word += char(i); Word += char(j); Word += char(k);
				Trials++;
				cout << "Trial [" << Trials << "] : " << Word << endl;
				if (Word == Password) {
					cout << "Password is " << Password << endl;
					cout << "Found after " << Trials << " Trial(s)" << endl;
					return true;
				}
				Word = "";
			}
		}
	}
}

int main() {

	guessPassword(readText("Enter a 3-Letter Password (Only Capital Letters) : "));

	return 0;
}