#include "SpacingGuildShip.hpp"
#include <iostream>
using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : maxPassengerCap(50), guildNavigatorCount(3), serialNum(producedShips + 1) {
/* Ctor default: jumlah penumpang adalah 0, jumlah Guild Navigator adalah 3,
 * Kapasitas pesawat adalah 50 orang, dan stok spice 50*/
	this->passengerCount = 0;
	this->operatingGuildNavigator = this->guildNavigatorCount;
	this->spiceStock = this->maxPassengerCap;
	SpacingGuildShip::producedShips ++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount), serialNum(producedShips + 1) {
/* Ctor jika diketahui jumlah Guild Navigator, kapasitas maksimal pesawat, 
 * dan stok spice. Jumlah penumpang 0 */
	this->passengerCount = 0;
	this->operatingGuildNavigator = guildNavigatorCount;
	this->spiceStock = spiceStock;
	SpacingGuildShip::producedShips ++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& newShip) : maxPassengerCap(newShip.maxPassengerCap), guildNavigatorCount(newShip.guildNavigatorCount), serialNum(producedShips + 1) {
/* Cctor SpacingGuildShip */
	this->passengerCount = newShip.passengerCount;
	this->operatingGuildNavigator = newShip.guildNavigatorCount;
	this->spiceStock = newShip.spiceStock;
	SpacingGuildShip::producedShips ++;
}

SpacingGuildShip::~SpacingGuildShip() {
/* Dtor SpacingGuildShip */

}

int SpacingGuildShip::getShipSerialNum() const {
/* Mengembalikan serial number dari pesawat */
	return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
/* Mengembalikan jumlah penumpang pesawat */
	return this->passengerCount;
}

void SpacingGuildShip::travel(float distance) {
/* Pesawat bergerak sebesar distance, sehingga 
 * totalGuildTravel bertambah sebesar:
 *
 * distance / (E^2 * operatingGuildNavigator).
 * 
 * Catatan: 
 * 1. Apabila tidak ada Guild Navigator yang operasional, 
 *    maka totalGuildTravel tidak bertambah;
 * 2. Apabila ada Guild Navigator yang operasional, 
 *    maka jumlah Guild Navigator operasional berkurang 1 */
	// jika ada
	if (this->operatingGuildNavigator > 0) {
		totalGuildTravel += (distance / (E * E * this->operatingGuildNavigator));
		operatingGuildNavigator--;
	}
}

void SpacingGuildShip::boarding(int addedPassengers) {
/* Penumpang naik ke pesawat sebesar addedPassenger. 
 * Jika pesawat tidak muat, penumpang pesawat menjadi penuh */
	int size = this->passengerCount;
	if (size + addedPassengers > this->maxPassengerCap) {
		this->passengerCount = this->maxPassengerCap;
	} else {
		this->passengerCount += addedPassengers;
	}
}

void SpacingGuildShip::dropOff(int droppedPassengers) {
/* Penumpang turun dari pesawat sebesar droppedPassenger. 
 * Jika jumlah penumpang kurang, kosongkan pesawat */
	int size = this->passengerCount;
	if (size - droppedPassengers < 0) {
		this->passengerCount = 0;
	} else {
		this->passengerCount -= droppedPassengers;
	}
}

void SpacingGuildShip::refreshNavigator(int n) {
/* Menambah n Guild Navigator operasional yang menghabiskan
 * n * GUILD_NAVIGATOR_SPICE_DOSE spice dari stok.
 * 
 * Catatan:
 * 1. Maksimum merefresh seluruh Guild Navigator yang ada di pesawat 
 * 2. Apabila stok kurang, maka merefresh n maksimum yang dapat di refresh
 *    dari stok spice yang ada */
	int currStock = this->spiceStock;
	while (currStock - n * GUILD_NAVIGATOR_SPICE_DOSE < 0) {
		n--;
	}
	this->operatingGuildNavigator += n;
	this->spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
/* Menambah stok spice sebesar addedSpice */
	this->spiceStock += addedSpice;
}