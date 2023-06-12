#include <iostream>
#include "RestoranRamen.hpp"

using namespace std;

// Menambah jumlah order yang dipesan oleh meja n, dengan harga p
// Jika meja sudah diisi maka akan menambah total yang telah dipesan
void RestoranRamen::tambahOrder(int n, int p) {
    if (this->daftarMeja.find(n) != this->daftarMeja.end()) {
    	this->daftarMeja[n] += p;
    } else {
    	this->daftarMeja.insert({ n, p });
    }
}

// Mengembalikan total harga pesanan pada meja n, menghapus entri untuk meja tersebut
int RestoranRamen::tutupOrder(int n) {
	int res = this->daftarMeja[n];
	this->daftarMeja.erase(n);

	return res;
}

// Mengembalikan total harga pesanan pada meja n
int RestoranRamen::cekTotal(int n) {
	return this->daftarMeja[n];
}

// Mengembalikan jumlah meja yang terisi saat itu
// Restoran mungkin kosong
int RestoranRamen::totalMeja() {
	return this->daftarMeja.size();
}

// Mencetak semua meja yang terisi pada restoran diakhiri dengan new line
// Contoh : 
/*
    Meja 1 = 5000
    Meja 2 = 3000
    Meja 4 = 10000
*/
// Jika restoran kosong akan mencetak "Restoran kosong" diakhiri new line
void RestoranRamen::cetakMeja() {
	if (this->totalMeja() != 0) {
		int i = 1;
		for (auto& t : this->daftarMeja) {
			cout << "Meja " << t.first << " = " << t.second << endl;
			i ++;
		}
	} else {
		cout << "Restoran kosong" << endl;
	}
}