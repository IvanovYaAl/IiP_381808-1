#pragma once
#include "Credit.h"
#include <string>

class ProcCenter {
private:
	int size;
	int buf;
	int current;
	string* fio;
	string* password;
	string* schet;
	Credit* cred;
	int numberr;//tekuschiy klient
public:
	ProcCenter();//default
	~ProcCenter();//destructor
	ProcCenter(int);//po umolchaniu
	int WhatNumberr();//kakoy tekuschiy klient
	Credit ReturnCred(int);//info about client
	bool Autolog(string _schet, string _password);// vhod v internet bank
	void ShowOpportunity();//pokazat' vozmojniy crediti
	void HaveCredit(Credit);//Vzati credit
	void CanTakeCredit(Credit);//Mojno li vzat' credit
	void AddNewClient();//Dobavlenie novogo clienta
	void ShowTable(Credit);//Pokazat' tekuschiy credit
	void DownMoney(Credit);//Pogasit' credit
	void ResetMoney(Credit);//Polojit' denigi na schet
	friend class Credit;
};