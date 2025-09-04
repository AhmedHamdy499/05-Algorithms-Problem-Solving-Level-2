#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enQuestionLevel { Beginner = 1, Easy = 2, Medium = 3, Hard = 4, Mix = 5 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, OpMix = 5 }; // Renamed Mix to OpMix

struct stQuestion {
	int Num1;
	int Num2;
	string Op;
	int Ans;
};

struct stFinalResults {
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
	int NumberOfQuestions = 0;
	int RightAnswers = 0;
	int	WrongAnswers = 0;
};

int ReadNumber() {
	int Num;
	cin >> Num;
	return Num;
}

int ReadNumberInRange(string Message, int Start, int End) {
	while (true) {
		int Num;
		cout << Message;
		cin >> Num;
		if (Num >= Start && Num <= End) {
			return Num;
		}
	}
}

int RandomNumber(int From, int To) {
	return rand() % ((To - From) + 1) + From;
}

int HowManyQuestions() {
	return ReadNumberInRange("How Many Questions Do You Want To Answer ( 1 -> 100 ) ? ", 1, 100);
}

string PrintCharacterLine(char Character, int Length) {
	string Line = "";
	for (int i = 1; i <= Length; i++) {
		Line += Character;
	}
	return Line;
}

enQuestionLevel ReadQuestionLevel() {
	return (enQuestionLevel)ReadNumberInRange("Enter Question Level [1] Beginner, [2] Easy, [3] Medium, [4] Hard, [5] Mix ? ", 1, 5);
}

enOperationType ReadOperationType() {
	return (enOperationType)ReadNumberInRange("Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? ", 1, 5);
}

string IdentifyOperationType(enOperationType Operation) {
	string Operations[4] = { "+", "-", "*", "/" };
	switch (Operation) {
		case enOperationType::Add:
			return "+";
		case enOperationType::Sub:
			return "-";
		case enOperationType::Mul:
			return "*";
		case enOperationType::Div:
			return "/";
		case enOperationType::OpMix: // Updated here
			return Operations[RandomNumber(0, 3)];
	}
}

string ShowQuestionLevel(enQuestionLevel Level) {
	switch (Level) {
	case enQuestionLevel::Beginner:
		return "Beginner";
	case enQuestionLevel::Easy:
		return "Easy";
	case enQuestionLevel::Medium:
		return "Medium";
	case enQuestionLevel::Hard:
		return "Hard";
	case enQuestionLevel::Mix:
		return "Mix";
	}
}

string ShowOperationType(enOperationType Operation) {
	switch (Operation) {
		case enOperationType::Add:
			return "Add";
		case enOperationType::Sub:
			return "Sub";
		case enOperationType::Mul:
			return "Mul";
		case enOperationType::Div:
			return "Div";
		case enOperationType::OpMix: // Updated here
			return "Mix";
	}
}

int CalculateAnswer(stQuestion Question) {
	if (Question.Op == "+") {
		return Question.Num1 + Question.Num2;
	}
	else if (Question.Op == "-") {
		return Question.Num1 - Question.Num2;
	}
	else if (Question.Op == "*") {
		return Question.Num1 * Question.Num2;
	}
	else if (Question.Op == "/") {
		return Question.Num1 / Question.Num2;
	}
}

stQuestion GenerateQuestion(enQuestionLevel Level, enOperationType Operation) {
	stQuestion Question;
	if (Level == enQuestionLevel::Beginner) {
		Question.Num1 = RandomNumber(1, 10);
		Question.Num2 = RandomNumber(1, 10);
	}
	else if (Level == enQuestionLevel::Easy) {
		Question.Num1 = RandomNumber(5, 20);
		Question.Num2 = RandomNumber(5, 10);
	}
	else if (Level == enQuestionLevel::Medium) {
		Question.Num1 = RandomNumber(20, 50);
		Question.Num2 = RandomNumber(5, 15);
	}
	else if (Level == enQuestionLevel::Hard) {
		Question.Num1 = RandomNumber(51, 99);
		Question.Num2 = RandomNumber(20, 50);
	}
	else if (Level == enQuestionLevel::Mix) {
		Question.Num1 = RandomNumber(1, 99);
		Question.Num2 = RandomNumber(1, 50);
	}
	Question.Op = IdentifyOperationType(Operation);
	Question.Ans = CalculateAnswer(Question);
	return Question;
}

void ShowQuestion(stQuestion Question) {
	cout << Question.Num1 << " " << Question.Op << " " << Question.Num2 << endl;
	cout << PrintCharacterLine('-', 6) << endl;
}

int ReadUserAnswer() {
	return ReadNumber();
}

bool isPassed(int RightAns, int WrongAns) {
	return RightAns >= WrongAns;
}

void ShowPassOrFail(int RightAns, int WrongAns) {
	cout << PrintCharacterLine('-', 30) << endl;
	if (isPassed(RightAns, WrongAns)) {
		cout << "  Final Results is Passed :)  " << endl;
	}
	else {
		cout << "  Final Results is Failed :(  " << endl;
	}
	cout << PrintCharacterLine('-', 30) << endl;
}

void ShowFinalResults(stFinalResults Results) {
	ShowPassOrFail(Results.RightAnswers, Results.WrongAnswers);
	cout << "Number Of Questions     : " << Results.NumberOfQuestions << endl;
	cout << "Questions Level         : " << ShowQuestionLevel(Results.QuestionLevel) << endl;
	cout << "Operation Type          : " << ShowOperationType(Results.OperationType) << endl;
	cout << "Number Of Right Answers : " << Results.RightAnswers << endl;
	cout << "Number Of Wrong Answers : " << Results.WrongAnswers << endl;
	cout << PrintCharacterLine('-', 30) << "\n" << endl;
}

void ResetScreen() {
	system("color 07");
	system("cls");
}

bool PlayAgain() {
	char userAns;
	cout << "Do You Want To Play Again ? (Y/N) ";
	cin >> userAns;
	return userAns == 'Y' || userAns == 'y';
}

void MathQuizGame() {
	stFinalResults Results;
	Results.NumberOfQuestions = HowManyQuestions();
	Results.QuestionLevel = ReadQuestionLevel();
	Results.OperationType = ReadOperationType();
	for (int Q = 1; Q <= Results.NumberOfQuestions; Q++) {
		cout << "Question [" << Q << "/" << Results.NumberOfQuestions << "] \n" << endl;
		stQuestion Question = GenerateQuestion(Results.QuestionLevel, Results.OperationType);
		ShowQuestion(Question);
		int UserAns = ReadUserAnswer();
		if (UserAns == Question.Ans) {
			system("color 20");
			cout << "Right Answer :)\n" << endl;
			Results.RightAnswers++;
		}
		else {
			system("color 40"); cout << "\a";
			cout << "Wrong Answer :(" << endl;
			cout << "The Right Answer is " << Question.Ans << "\n" << endl;
			Results.WrongAnswers++;
		}
	}
	ShowFinalResults(Results);
}

void StartGame() {
	do {
		ResetScreen();
		MathQuizGame();
	} while (PlayAgain());
}

int main() {
	srand(time(NULL));

	StartGame();

	return 0;
}