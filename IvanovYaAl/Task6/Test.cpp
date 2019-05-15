#include "Game.h"

int main() {
	int nun;
	srand(time(0));
	cout << "Rules: They play two players (man and computer).\nThe player chooses the length of the guess number - n.\nThe computer conceivesan n - digit number with non - repeating numbers.\nThe player makes an attempt to guess the number - enters an n - digit number with non - recurring digits.\nThe computer reports how many digits are guessed without coinciding with their positions in the hidden number(that is, the number of cows) and how many are guessed right up to the position in the hidden number(that is, the number of bulls).\nThe player makes attempts until the entire sequence is guessed." << endl;
restart:
	cout << "Enter the count of numbers: " << endl;
	cin >> nun;
	Game A(nun);
	cout << "Game Start!" << endl;
	A.Start();
	cout << "Restart?(1. Yes/2. No): " << endl;
	int f;
	cin >> f;
	if (f == 1)goto restart;
	system("pause");
}