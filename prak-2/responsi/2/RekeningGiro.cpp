#include <iostream>
#include "RekeningGiro.h"

using namespace std;

// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double saldo, double x) : Rekening(saldo) {
	if (x >= 0) {
		this->sukuBunga = x;
	} else {
		this->sukuBunga = 0;
	}
}

// Getter, Setter
void RekeningGiro::setSukuBunga(double x) {
	this->sukuBunga = x;
}

double RekeningGiro::getSukuBunga() const {
	return this->sukuBunga;
}

// Member Function
// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga() {
	return (this->getSaldo() * this->getSukuBunga());
}