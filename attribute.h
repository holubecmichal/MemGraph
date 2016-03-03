//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTE_H
#define BACHELOR_ATTRIBUTE_H


#include <string>
#include <utility>
#include <iostream>
#include <map>

enum attr_type {
	type_null,
	type_int,
	type_double,
	type_string,
	type_bool
};

class Attribute {
private:
	int i_value;
	double d_value;
	const char *s_value;
	bool b_value;
	attr_type type;
	const char *name;

	void setType(int value)          { type = type_int; }
	void setType(double value)       { type = type_double; }
	void setType(const char * value) { type = type_string; }
	void setType(bool value)         { type = type_bool; }

	void init() {
		type = type_null;
		i_value = 0;
		d_value = 0;
		s_value = "";
		b_value = false;
	}

public:
	Attribute() {
		init();
	};

	template <typename T>
	Attribute(const char *name, T value) {
		this->name = name;
		setValue(value);
	}

	void setValue(int value)          { init(); i_value = value; setType(value); }
	void setValue(double value)       { init(); d_value = value; setType(value); }
	void setValue(const char * value) { init(); s_value = value; setType(value); }
	void setValue(bool value)         { init();	b_value = value; setType(value); }

	int         getIValue() { return i_value; }
	double      getDValue() { return d_value; }
	const char *getSValue() { return s_value; };
	bool        getBValue() { return b_value; };

	const char *getValue();
	attr_type getType();
	void setName(const char *name);

	bool useQuotationMarks();

//	attr_type getType()
};


#endif //BACHELOR_ATTRIBUTE_H
