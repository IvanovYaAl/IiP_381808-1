#include "ProcCenter.h"

ProcCenter::ProcCenter() {
	size = 0;
	buf = 5;
	current = 0;
	fio = NULL;
	password = NULL;
	schet = NULL;
	cred = NULL;
	numberr = 0;
}

ProcCenter::~ProcCenter() {
	size = 0;
	buf = 0;
	current = 0;
	numberr = 0;
	delete[] fio;
	fio = NULL;
	delete[] password;
	password = NULL;
	delete[] schet;
	schet = NULL;
	delete[] cred;
	cred = NULL;
}
ProcCenter::ProcCenter(int _size) {
	size = _size;
	buf = size + 10;
	cred = new Credit[buf];
	fio = new string[buf];
	password = new string[buf];
	schet = new string[buf];
}

bool ProcCenter::Autolog(string _schet, string _password) {
	int numb = 0;
	for (int i = 0; i < size; i++) {
		if (_schet == schet[i] && _password == password[i]) {
			numb = 1;
			numberr = i;
			return true;
		}
	}
	if (numb == 0) {
		cout << "This account was not found in the database or an incorrect password." << endl;
		return false;
	}
}
void ProcCenter::ShowOpportunity() {
	cout << "Choose how money u want take:\n";
	cout << "1. <100,000\n2. from 100,000 to 500,000\n3. from 500,000 to 1,000,000\n4. from 1,000,000 to 3,000,000" << endl;
	int choice;
	cin >> choice;
	cout << "For what time: " << endl;
	int ch;
	cout << "1. 1 year.\n2. 2 years.\n3. 3 years.\n4. 5 years.\n5. 15 years." << endl;
	cin >> ch;
	double ur[5][6] = {
		{0.14,0.15,0.16,0.17},
		{0.13,0.14,0.15,0.16},
		{0.10,0.11,0.12,0.13},
		{0.09,0.10,0.11,0.12},
		{0.08,0.09,0.10,0.11}
	};
	cout << "% = " << ur[ch - 1][choice - 1] << endl;
}
int ProcCenter::WhatNumberr() {
	return numberr;
}
Credit ProcCenter::ReturnCred(int pp) {
	return cred[pp];
}
void ProcCenter::HaveCredit(Credit some) {
	if (some.Real() == false) {
		cout << "You have no credit, congratulations!" << endl;
	}
	else {
		cout << "You took a loan from the bank: " << some.summa_credita_() << endl;
	}
}
void ProcCenter::CanTakeCredit(Credit some) {
	cout << "Enter the amount you want to borrow (from 1 rub to 3,000,000 rub): " << endl;
	int rub;
	cin >> rub;
	double ur[5][6] = {
		{0.14,0.15,0.16,0.17},
		{0.13,0.14,0.15,0.16},
		{0.10,0.11,0.12,0.13},
		{0.09,0.10,0.11,0.12},
		{0.08,0.09,0.10,0.11}
	};
	cout << "For what time: " << endl;
	int year;
	cin >> year;
	int first, second;
	if (rub < 100000)first = 1;
	if (rub >= 100000 && rub < 500000) first = 2;
	if (rub >= 500000 && rub < 1000000) first = 3;
	if (rub >= 1000000 && rub < 3000000)first = 4;
	if (year == 1)second = 1;
	if (year == 2)second = 2;
	if (year == 3)second = 3;
	if (year == 5)second = 4;
	if (year == 15)second = 5;
	double percent = ur[second - 1][first - 1];
	int need = some.summa_na_schetu_() / 6;
	if (((rub + (rub*percent)) / (2 * year) < some.summa_na_schetu_()) && (some.Real() == false)) {
		cout << "You can take this credit" << endl;
		cout << "Do you want take this credit?\n1. Yes.\n2. No." << endl;
		int lp;
		cin >> lp;
		int flag = 0;
		if (lp == 1) {
			cout << "Enter your numb accaount: " << endl;
			string acc;
			cin >> acc;
			for (int i = 0; i < size; i++) {
				if (acc == schet[i]) {
					flag = i;
				}
			}
			cred[flag].GetStavka(percent);
			cred[flag].GetNazivin(true);
			cred[flag].GetSummaCredita(rub);
			cred[flag].GetSummaScheta(some.summa_na_schetu_());
			cred[flag].GetViplata(rub / year * (1 + percent) / 12);
			cout << "Congratulations you took out a loan!" << endl;
		}
	}
	else
		cout << "You can't take this credit, please try again later." << endl;
}
void ProcCenter::AddNewClient() {
	cout << "Enter your FIO: " << endl;
	cin >> fio[current];
	cout << "Create your password: " << endl;
	cin >> password[current];
	cout << "Create your number of account (from 0001 to 9999): " << endl;
	string nu;
plag:
	cin >> nu;
	for (int i = 0; i < size; i++) {
		if (nu == schet[i]) {
			cout << "Create another number: " << endl;
			goto plag;
		}
	}
	schet[current] = nu;
	cout << "Enter the amount of money in the account at the moment: " << endl;
	int io;
	cin >> io;
	cred[current].GetSummaScheta(io);
	cout << "Congratulations you are registered" << endl;
	current++;
}
void ProcCenter::ShowTable(Credit pole) {
	cout << "Stavka: " << pole.stavka_() << endl;
	cout << "Ostatok Kredita: " << pole.summa_credita_() << endl;
}
void ProcCenter::DownMoney(Credit pole) {
	cout << "Do you want make a payment? (1. Yes/ 2. No): " << endl;
	int t;
	cin >> t;
	if (t == 2) {
		cout << "Please try something else." << endl;
	}
	else {
		cout << "Enter total money what you want pay: " << endl;
		int money;
		cin >> money;
		pole.GetSummaCredita(pole.summa_credita_() - money);
		pole.GetSummaScheta(pole.summa_na_schetu_() - money);
		cout << "Left to repay: " << pole.summa_credita_() << endl;
	}
	if (pole.summa_credita_() <= 0) {
		cout << "Congratulations you repaid the loan!!" << endl;
	}
}
void ProcCenter::ResetMoney(Credit pole) {
	cout << "How much money you want put on the account? " << endl;
	int moon;
	cin >> moon;
	pole.GetSummaScheta(pole.summa_na_schetu_() + moon);
}