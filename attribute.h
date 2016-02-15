//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTE_H
#define BACHELOR_ATTRIBUTE_H


#include <string>

enum attr_type {
	type_int,
	type_double,
	type_string,
	type_bool
};

class attribute {
private:
	int type;
	int tint;
	double tdouble;
	std::string tstring;
	bool tbool;

	void setType();

public:
	int setValue(int value);
	int setValue(double value);
	int setValue(std::string value);
	int setValue(bool value);

	attr_type getType();

	template <typename varType>
		varType getValue();
};


#endif //BACHELOR_ATTRIBUTE_H
