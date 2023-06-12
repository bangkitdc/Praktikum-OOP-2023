#include <iostream>
#include "Kompleks.h"
using namespace std;

#define KK Kompleks

int KK::n_kompleks = 0;

// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
KK::Kompleks() : Kompleks(0, 0) {

}

// ctor dengan parameter
KK::Kompleks(int real, int imaginer) {
	this->real = real;
	this->imaginer = imaginer;
	KK::n_kompleks++;
}

//mengembalikan bagian riil
int KK::GetReal() const {
	return this->real;
}

// mengembalikan bagian imaginer
int KK::GetImaginer() const {
	return this->imaginer;
}

// mengisi bagian riil
void KK::SetReal(int x) {
	this->real = x;
}

// mengisi bagian imaginer
void KK::SetImaginer(int y) {
	this->imaginer = y;
}

// operator overloading

// operator+ untuk melakukan penjumlahan dengan rumus berikut
// (a + bi) + (c + di) = (a+c) + (b+d)i
Kompleks operator+ (const Kompleks& a, const Kompleks& b) {
	KK res;

	res.real = (a.GetReal() + b.GetReal());
	res.imaginer = (a.GetImaginer() + b.GetImaginer());

	return res;
}

// operator- untuk melakukan pengurangan dengan rumus berikut
// (a + bi) − (c + di) = (a−c) + (b−d)i
Kompleks operator- (const Kompleks& a, const Kompleks& b) {
	KK res;

	res.real = (a.GetReal() - b.GetReal());
	res.imaginer = (a.GetImaginer() - b.GetImaginer());

	return res;
}

// operator* untuk melakukan perkalian dengan rumus berikut
// (a + bi)(c + di) = ac + bci + adi + bd i^2 = (ac−bd) + (bc+ad)i
Kompleks operator* (const Kompleks& a, const Kompleks& b) {
	KK res;

	res.real = ((a.GetReal() * b.GetReal()) - (a.GetImaginer() * b.GetImaginer()));
	res.imaginer = ((a.GetImaginer() * b.GetReal()) + (a.GetReal() * b.GetImaginer()));

	return res;
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta
// (a + bi)(c) = (ac) + (bc)i
Kompleks operator* (const Kompleks& a, const int x) {
	KK res;

	res.real = (a.GetReal() * x);
	res.imaginer = (a.GetImaginer() * x);

	return res;
}

// operator* untuk mengkalikan bilangan kompleks dengan konstanta (sifat komutatif)
Kompleks operator* (const int x, const Kompleks& a) {
	KK res(a);

	return res * x;
}

// mengembalikan jumlah instance yang pernah dibuat
int KK::CountKompleksInstance() {
	return KK::n_kompleks;
}

// mencetak bilangan kompleks ke layar, diakhiri dengan end-of-line 
// contoh:
// 3+5i
// 0+0i
// -5-4i
void KK::Print() {
	cout << this->real;
	if (this->imaginer >= 0) {
		cout << "+";
	}
	cout << this->imaginer << "i" << endl;
}