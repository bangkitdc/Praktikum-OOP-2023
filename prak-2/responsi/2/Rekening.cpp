#include <iostream>
#include "Rekening.h"

using namespace std;

// Konstruktor untuk menginisialisasi saldo
// Set saldo 0.0 apabila saldo bernilai negatif
Rekening::Rekening(double x) {
	if (x >= 0) {
		this->saldo = x;
	} else {
		this->saldo = 0;
	}
}

// Getter, Setter
void Rekening::setSaldo(double x) {
	this->saldo = x;
}

double Rekening::getSaldo() const {
	return this->saldo;
}

// Member Function
// Tambahkan sejumlah nominal uang ke saldo
void Rekening::simpanUang(double x) {
	this->saldo += x;
}

// Kurangkan sejumlah nominal uang dari saldo apabila saldo mencukupi (tidak negatif setelah dikurangkan)
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool Rekening::tarikUang(double x) {
	if (this->getSaldo() - x >= 0) {
		this->simpanUang(-x);
		return true;
	}
	return false;
}