//
// Created by Michael Holubec on 15.02.16.
//

#include "attribute.h"

void attribute::setType() {

}

int attribute::setValue(int value) {
	return 0;
}

int attribute::setValue(double value) {
	return 0;
}

int attribute::setValue(std::string value) {
	return 0;
}

int attribute::setValue(bool value) {
	return 0;
}

attr_type attribute::getType() {
	return type_int;
}

template<typename varType>
varType attribute::getValue() {
	return nullptr;
}
