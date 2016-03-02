//
// Created by Michael Holubec on 15.02.16.
//

#include <sstream>
#include "attribute.h"

attr_type Attribute::getType() {
	return type;
}

const char *Attribute::getValue() {
	std::string value;
	std::ostringstream strs;

	switch (getType()) {
		case type_int:
			strs << getIValue();
			value = strs.str();
			break;
		case type_bool:
			if(getBValue()) {
				value = "true";
			} else {
				value = "false";
			}
			break;
		case type_string:
			value = getSValue();
			break;
		case type_double:
			strs << getDValue();
			value = strs.str();
			break;
		default:
			break;
	}

	return value.c_str();
}
