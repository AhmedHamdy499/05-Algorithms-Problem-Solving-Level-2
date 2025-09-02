#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
* N (Any Number)  %  M   => Output [0, M - 1]
* 56674 % 50 => Output [0, 49]
* 98997 % 33 => Output [0, 32]
* rand() % 21 => Output [0, 20]  , Adding 20 to the output makes shift , Output + 20 => [20, 40]
* (To - From ) + 1 => Range , Adding 1 to include the last number in range , as you know rand() % 21 => Output [0, 20]
* Adding From to Make a Shift..
*/

int randomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

int main() {
	srand(time(NULL));

	cout << randomNumber(10,30) << endl;
	cout << randomNumber(40, 70) << endl;
	cout << randomNumber(100, 110) << endl;

	return 0;
}