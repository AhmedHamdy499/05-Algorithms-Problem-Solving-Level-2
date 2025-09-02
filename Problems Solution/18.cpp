#include <iostream>
using namespace std;

int readNumber(string Message) {
	int Num;
	cout << Message << endl;
	cin >> Num;
	return Num;
}

string readText(string Message) {
	string Text;
	cout << Message << endl;
	cin >> Text;
	return Text;
}

string reverseString(string st) {
	string reversedString;
	for (int i = st.length() - 1; i >= 0; i--) {
		reversedString += st[i];
	}
	return reversedString;
}

string encryptionPassword(int encryptionKey, string Password) {
	string encryptedPassword = "";

	for (int i = 0; i < Password.length(); i++) {
		encryptedPassword += char(Password[i] + encryptionKey);
	}

	return reverseString(encryptedPassword);
}

string decryptionPassword(int decryptionKey, string encryptedPassword) {
	encryptedPassword = reverseString(encryptedPassword);
	string Password = "";
	
	for (int i = 0; i < encryptedPassword.length(); i++) {
		Password += char(encryptedPassword[i] - decryptionKey);
	}

	return Password;
}

int main() {
	string Password = readText("Enter the password : ");
	int encryptionKey = readNumber("Enter encryptionKey : ");

	string encryptedPassword = encryptionPassword(encryptionKey, Password);
	string decryptedPassword = decryptionPassword(encryptionKey, encryptedPassword);

	cout << "*************************************************************\n";

	cout << "Password Before Encryption : " << Password << endl;
	cout << "Password After Encryption  : " << encryptedPassword << endl;
	cout << "Password After Decryption  : " << decryptedPassword << endl;

	cout << "*************************************************************\n";


	return 0;
}