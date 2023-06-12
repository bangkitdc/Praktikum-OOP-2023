#include <iostream>
#include "RekeningTabungan.h"

using namespace std;

// Konstruktor menginisialisi saldo (parameter 1) dan biaya transaksi (parameter 2)
// Set biaya transaksi 0.0 apabila biaya transaksi bernilai negatif
RekeningTabungan::RekeningTabungan(double saldo, double x) : Rekening(saldo) {
	if (x >= 0) {
		this->biayaTransaksi = x;
	} else {
		this->biayaTransaksi = 0;
	}
}

// Getter, Setter
void RekeningTabungan::setBiayaTransaksi(double x) {
	this->biayaTransaksi = x;
}

double RekeningTabungan::getBiayaTransaksi() const {
	return this->biayaTransaksi;
}

// Member Function
// Panggil fungsi simpanUang dari parent class
// Kurangkan saldo dengan biaya transaksi
void RekeningTabungan::simpanUang(double uang) {
	Rekening::simpanUang(uang - this->getBiayaTransaksi());
}

// Panggil fungsi tarikUang dari parent class
// Kurangkan saldo dengan biaya transaksi hanya jika penarikan uang berhasil
// Saldo mungkin saja menjadi negatif apabila setelah penarikan, saldo < biaya transaksi
// Kembalikan boolean yang mengindikasikan apakah uang berhasil ditarik atau tidak
bool RekeningTabungan::tarikUang(double uang) {
	if(Rekening::tarikUang(uang)) {
		this->setSaldo(this->getSaldo() - this->getBiayaTransaksi());
		return true;
	} 
	return false;
}