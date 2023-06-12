#include <iostream>
#include "BunchOfKeys.hpp"

using namespace std;

#define BB BunchOfKeys

// ctor
BB::BunchOfKeys() {
	this->n_keys = 0;
}

// member function
void BB::add() {
	this->n_keys++;
}

void BB::shake() {
	if (this->n_keys <= 1) {
		cout << "Tidak terjadi apa-apa" << endl;
	} else {
		for (int i = 0; i < this->n_keys; i ++) {
			cout << "krincing" << endl;
		}
	}
}