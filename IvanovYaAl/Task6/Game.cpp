#include "Game.h"

Game::Game(int n) {
	chisl = n;
	srand(time(0));
	number = 0;
	int o;
	int mass[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int mass1[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1 };
	for (int i = 0; i < n; i++) {
	ag:
		o = rand() % (10);
		if (o == 0 && i == 0)goto ag;
		if ((o != mass1[0]) && (o != mass1[1]) && (o != mass1[2]) && (o != mass1[3]) && (o != mass1[4]) && (o != mass1[5]) && (o != mass1[6]) && (o != mass1[7]) && (o != mass1[8]) && (o != mass1[9])) {
			number += o;
			if ((n - 1) != i)number *= 10;
			mass1[o] = o;
		}
		else goto ag;
	}
}
Game::~Game() {
	number = 0;
	pole = 0;
	chisl = 0;
}
void Game::Start() {
urb:
	cout << "Insert the number: " << endl;
	cin >> pole;
	int cows = 0, bulls = 0;
	int* my;
	int* my1;
	my = new int[chisl];
	my1 = new int[chisl];
	for (int i = 0; i < chisl; i++) {
		my1[i] = (pole / (pow(10, chisl - 1 - i)));
		int p = my1[i] % 10;
		my1[i] = p;
		my[i] = number / (pow(10, chisl - 1 - i));
		int p1 = my[i] % 10;
		my[i] = p1;
	}
	for (int i = 0; i < chisl; i++) {
		if (my1[i] == my[i]) {
			bulls++;
		}
		else {
			for (int j = 0; j < chisl; j++) {
				if (my[i] == my1[j] && i != j) {
					cows++;
				}
			}
		}
	}
	cout << "Cows: " << cows << "  Bulls: " << bulls << endl;
	delete my;
	delete my1;
	if (bulls == chisl) {
		cout << "Congratulations you won !!!" << endl;
		goto exit;
	}
	goto urb;
exit:
	cout << "" << endl;
}
