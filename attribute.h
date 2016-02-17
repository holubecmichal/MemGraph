//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTE_H
#define BACHELOR_ATTRIBUTE_H


#include <string>
#include <iostream>

enum attr_type {
	type_null,
	type_int,
	type_double,
	type_string,
	type_bool
};

template <typename T>
class attribute{
private:
	T value;
	attr_type type;
	void setType(T val) {
		if(typeid(val) == typeid(int)) {
			type = type_int;
		} else if(typeid(val) == typeid(double)) {
			type = type_double;
		} else if(typeid(val) == typeid(std::string)) {
			type = type_string;
		} else if(typeid(val) == typeid(bool)) {
			type = type_bool;
		} else {
			type = type_null;
		}
	};

public:
	attribute() {
		type = type_null;
		value = type_null;
	};

	attribute(T val) {
		value = val;
		setType(val);
	};

	void setValue(T val) {
		value = val;
		setType(val);
	};

	T getValue() {
		return value;
	};

	attr_type getType() {
		return type;
	};
};


#endif //BACHELOR_ATTRIBUTE_H
