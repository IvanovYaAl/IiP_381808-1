#pragma once
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

class Game {
private:
	long int number;
	int pole;
	int chisl;
public:
	Game(int);
	~Game();
	void Start();
};