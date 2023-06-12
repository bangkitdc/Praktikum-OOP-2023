#include "DepreciatingAsset.hpp"
#include "BaseAsset.hpp"
#include <iostream>

double DepreciatingAsset::getValue(int years) {
	double value = 1;

	for (int i = 0; i < years; i ++) {
		value = value * (1 - this->rate);
	}

	return this->x->getValue(years) * value;
}