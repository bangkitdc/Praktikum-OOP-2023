#include "memo.h"
#include <iostream>

using namespace std;

/* 
	Membuat objek Memo dengan 'pesan' dan 'untuk' kosong
*/
Memo::Memo() : Memo("", "") { }
/* 
	Membuat objek Memo dengan isi sesuai yang diberikan.
	
	Jika panjang pesan melebihi panjang maksimum, maka
	metode ini melemparkan PesanKepanjanganException.
*/
Memo::Memo(string pesan, string untuk) {
	if (pesan.length() > this->PESAN_MAX) {
		throw PesanKepanjanganException();
	}

	this->pesan = pesan;
	this->untuk = untuk;
}
/* 
	Menyalin nilai pesan dan untuk ke objek lain
*/
Memo& Memo::operator=(Memo& obj) {
	this->pesan = obj.pesan;
	this->untuk = obj.untuk;
}
/*
	Mendapatkan nilai pesan
*/
string Memo::getPesan() {
	return this->pesan;
}
/*
	Mendapatkan nilai untuk
*/
string Memo::getUntuk() {
	return this->untuk;
}