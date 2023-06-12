#include <iostream>
using namespace std;

#include "ExplodableBarrel.hpp"
#include "Damageable.hpp"
#include "Explodable.hpp"

// Default Constructor
// health dari ExplodableBarrel selalu 1 dan
// default radiusnya adalah 5
ExplodableBarrel::ExplodableBarrel() : Explodable(), Damageable(1) {
	this->radius = 5;
}

// Masukan: radius (integer positif) dan baseDamage (integer positif)
// health dari ExplodableBarrel selalu 1
ExplodableBarrel::ExplodableBarrel(int radius, int baseDamage) : Explodable(baseDamage), Damageable(1) {
	this->radius = radius;
}

// Masukan: damage (integer positif) dan element (string)
//
// Berikut adalah urutan aksi yang dilakukan:
//
// Apabila barrel telah hancur, maka tidak akan terjadi
// apa-apa.
//
// Barrel menerima damage dan tidak menghiraukan element.
// Apabila barrel hancur setelah menerima damage, maka
// barrel akan meledak sebesar radius yang telah ditentukan.
void ExplodableBarrel::takeDamage(int damage, string element) {
	if (!this->isDestroyed()) {
		Damageable::takeDamage(damage);
		if (this->isDestroyed()) {
			Explodable::explode(this->radius);
		}
	}
}