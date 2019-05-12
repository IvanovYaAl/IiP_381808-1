#pragma once
#include <iostream>

using namespace std;

class Credit {
private:
	double stavka;//% stavki
	int summa_credita;// summa credita
	int summa_na_schetu;// summa na schetu cheloveka
	int viplata;// ejemesechtaya viplata
	bool nazivin;// est' li credit
public:
	Credit();//default
	~Credit();//destructor
	int summa_credita_();//vozvrashaet summu credita
	int summa_na_schetu_();//vozvrashaet summu na schetu
	double stavka_();//vozvrashaet % stavki
	void GetSummaCredita(int);//poluchaet summu credita
	void GetSummaScheta(int);///poluchaet summu na schetu
	void GetViplata(int);//poluchaet summu viplati
	void GetStavka(double);//poluchaet % stavki
	void GetNazivin(bool);//poluchaet istinost' credita
	bool Real();//vozvrashaet istinost' credita
	friend class ProcCenter;
};