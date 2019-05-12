#include "Credit.h"

Credit::Credit() {
	stavka = 0;
	summa_credita = 0;
	summa_na_schetu = 0;
	viplata = 0;
	nazivin = false;
}
Credit::~Credit() {
	stavka = 0;
	summa_credita = 0;
	summa_na_schetu = 0;
	viplata = 0;
	nazivin = false;
}

void Credit::GetStavka(double _stav) {
	stavka = _stav;
}
bool Credit::Real() {
	return nazivin;
}
int Credit::summa_credita_() {
	return summa_credita;
}
int Credit::summa_na_schetu_() {
	return summa_na_schetu;
}
void Credit::GetSummaCredita(int one) {
	summa_credita = one;
}
void Credit::GetSummaScheta(int one) {
	summa_na_schetu = one;
}
void Credit::GetViplata(int one) {
	viplata = one;
}
void Credit::GetNazivin(bool one) {
	nazivin = one;
}
double Credit::stavka_() {
	return stavka;
}