#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enRPS { Rock = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player, Computer, Draw };

enum enScreenColor { Red, Green, Orange };

struct stRoundDetails {
	string playerChoice, computerChoice, winner;
};

struct stResults {
	int playerWonTimes = 0, computerWinTimes = 0, Draw = 0;
};

string printCharacterLine(char Character, int Length) {
	string Line = "";
	for (int i = 1; i <= Length; i++) {
		Line += Character;
	}
	return Line;
}

int readNumberInRange(string Message, int From ,int To) {
	while (true) {
		int Num;
		cout << Message << endl;
		cin >> Num;
		if (Num >= From && Num <= To) {
			return Num;
		}
		else {
			cout << printCharacterLine('*', 15) << endl;
			cout << "Wrong Input!!" << endl;
			cout << printCharacterLine('*', 15) << endl;
		}
	}

}

int randomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

bool isLower(char ch) {
	return (ch >= 'a' && ch <= 'z');
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

void setColor(enScreenColor Color) {
	switch (Color) {
	case enScreenColor::Green:
	{
		system("color 20");
		break;
	}
	case enScreenColor::Red:
	{
		system("color 40");
		break;
	}
	case enScreenColor::Orange:
	{
		system("color 60");
		break;
	}
	}
}

int numberOfRounds() {
	return readNumberInRange("How Many Rounds 1 -> 10 ? ", 1, 10);
}

void roundBeginning(int roundNumber) {
	cout << "Round [" << roundNumber << "] Begins : " << endl;
}

bool choiceValidation(short playerChoice) {
	return playerChoice >= 1 && playerChoice <= 3;
}

string identifyChoice(short Choice) {
	switch (Choice) {
		case enRPS::Rock:
		{
			return "Rock";
		}
		case enRPS::Paper:
		{
			return "Paper";
		}
		case enRPS::Scissors:
		{
			return "Scissors";
		}
	}
}

string identifyWinner(short Winner) {
	switch (Winner) {
	case enWinner::Player:
	{
		return "Player";
	}
	case enWinner::Computer:
	{
		return "Computer";
	}
	case enWinner::Draw:
	{
		return "Draw";
	}
	}

}

string getPlayerChoice() {
	short playerChoice = readNumberInRange("Your Choice -> (1) Rock - (2) Paper - (3) Scissors <- ? ", 1, 3);
	return identifyChoice(playerChoice);
}

string getComputerChoice() {
	return identifyChoice(randomNumber(1, 3));
}

string getWinner(string playerChoice, string computerChoice) {
	if (playerChoice == computerChoice) {
		setColor(enScreenColor::Orange);
		return identifyWinner(enWinner::Draw);
	}
	else if (playerChoice == identifyChoice(enRPS::Rock)) {
		if (computerChoice == identifyChoice(enRPS::Paper)) {
			setColor(enScreenColor::Red);
			return identifyWinner(enWinner::Computer);
		}
		else if (computerChoice == identifyChoice(enRPS::Scissors)) {
			setColor(enScreenColor::Green);
			return identifyWinner(enWinner::Player);
		}
	}
	else if (playerChoice == identifyChoice(enRPS::Paper)) {
		if (computerChoice == identifyChoice(enRPS::Rock)) {
			setColor(enScreenColor::Green);
			return identifyWinner(enWinner::Player);
		}
		else if (computerChoice == identifyChoice(enRPS::Scissors)) {
			setColor(enScreenColor::Red);
			return identifyWinner(enWinner::Computer);
		}
	}
	else if (playerChoice == identifyChoice(enRPS::Scissors)) {
		if (computerChoice == identifyChoice(enRPS::Paper)) {
			setColor(enScreenColor::Green);
			return identifyWinner(enWinner::Player);
		}
		else if (computerChoice == identifyChoice(enRPS::Rock)) {
			setColor(enScreenColor::Red);
			return identifyWinner(enWinner::Computer);
		}
	}
}

stRoundDetails fillRoundResult(string playerChoice, string computerChoice) {
	stRoundDetails Details;
	Details.playerChoice = playerChoice;
	Details.computerChoice = computerChoice;
	Details.winner = getWinner(playerChoice, computerChoice);
	return Details;
}

void printRoundResult(int roundNumber, stRoundDetails Detalis) {
	cout << "\n";
	cout << printCharacterLine('-', 8) << " Round [" << roundNumber << "] " << printCharacterLine('-', 8) << endl;
	cout << "Player Choice   : " << Detalis.playerChoice << endl;
	cout << "Computer Choice : " << Detalis.computerChoice << endl;
	cout << "Round Winner    : " << Detalis.winner << endl;
	cout << printCharacterLine('-', 27) << endl;
	cout << "\n";
}

stRoundDetails newRound(int roundNumber) {
	roundBeginning(roundNumber);
	stRoundDetails roundDetails = fillRoundResult(getPlayerChoice(), getComputerChoice());
	return roundDetails;
}

string getFinalWinner(stResults Results) {
	if (Results.playerWonTimes > Results.computerWinTimes) {
		return "Player";
	}
	else if (Results.computerWinTimes > Results.playerWonTimes) {
		return "Computer";
	}
	else {
		return "No Winner";
	}
}

void fillAllRoundsResults(stResults &Results,stRoundDetails roundDetails) {
	if (roundDetails.winner == "Computer") {
		Results.computerWinTimes++;
	}
	else if (roundDetails.winner == "Player") {
		Results.playerWonTimes++;
	}
	else {
		Results.Draw++;
	}
}

void printAllRoundsResults(int rounds,stResults Results) {
	cout << "\n";
	cout << printCharacterLine('\t', 4) << printCharacterLine('-', 60) << endl;
	cout << printCharacterLine('\t', 6) << "+++  G a m e  O v e r  +++" << endl;
	cout << printCharacterLine('\t', 4) << printCharacterLine('-', 60) << endl;
	cout << printCharacterLine('\t', 4) << printCharacterLine('-', 22) << " [Game Results] " << printCharacterLine('-', 22) << endl;
	cout << "\n";
	cout << printCharacterLine('\t', 4) << "Game Rounds        : " << rounds << endl;
	cout << printCharacterLine('\t', 4) << "Player Won Times   : " << Results.playerWonTimes << endl;
	cout << printCharacterLine('\t', 4) << "Computer Won Times : " << Results.computerWinTimes << endl;
	cout << printCharacterLine('\t', 4) << "Draw Times         : " << Results.Draw << endl;
	cout << printCharacterLine('\t', 4) << "Final Winner       : " << getFinalWinner(Results) << endl;
	cout << "\n";
	cout << printCharacterLine('\t', 4) << printCharacterLine('-', 60) << endl;
}

void RockPaperScissors() {
	int rounds = numberOfRounds();
	stResults Results;
	for (int i = 1; i <= rounds; i++) {
		stRoundDetails roundDetails = newRound(i);
		printRoundResult(i, roundDetails);
		fillAllRoundsResults(Results, roundDetails);
	}
	printAllRoundsResults(rounds, Results);
}

bool playAgain() {
	string userAns;
	cout << printCharacterLine('\t', 4) << "Do You Want To Play Again ? (Y/N) ";
	cin >> userAns;
	if (setUpper(userAns) == "Y") {
		return true;
	}
	else {
		return false;
	}
}

void resetScreen() {
	system("color 07");
	system("cls");
}

void StartGame() {
	do
	{
		resetScreen();
		RockPaperScissors();
	} while (playAgain());
}

int main() {
	srand(time(NULL));

	StartGame();

	return 0;
}