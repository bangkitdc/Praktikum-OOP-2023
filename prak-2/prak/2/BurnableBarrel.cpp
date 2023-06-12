#include <iostream>
using namespace std;

#include "BurnableBarrel.hpp"
#include "Burnable.hpp"
#include "Damageable.hpp"

// Default Constructor
BurnableBarrel::BurnableBarrel() : Damageable(), Burnable() {

}

// Masukan: health (integer positif)
BurnableBarrel::BurnableBarrel(int health) : Damageable(health), Burnable() {

}

// Masukan: damage (integer positif) dan element (string)
//
// Berikut adalah urutan aksi yang dilakukan:
//
// Apabila barrel telah hancur, maka tidak akan terjadi
// apa-apa.
//
// Apabila barrel menerima damage element berupa "fire",
// maka akan mengaktifkan status burned. Apabila barrel
// menerima damage element berupa "water", maka status
// burned akan dinonaktifkan.
//
// Setelah update status burned, Jika barrel dalam kondisi
// burned, maka damagenya akan dikalikan dengan konstanta
// multiplier. Jika tidak, maka damagenya tidak berubah.
void BurnableBarrel::takeDamage(int damage, string element) {
	if (!this->isDestroyed()) {
		if (element == "fire") {
			this->burn();
		} else if (element == "water") {
			this->watered();
		}

		if (this->isBurned()) {
			Damageable::takeDamage(damage * this->multiplier);
		} else {
			Damageable::takeDamage(damage);
		}
	}
}