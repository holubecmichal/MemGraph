//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTE_H
#define BACHELOR_ATTRIBUTE_H


#include <string>
#include <utility>
#include <iostream>
#include <map>



class Attribute {
public:
	enum attr_type {
		type_null,
		type_int,
		type_double,
		type_string,
		type_bool
	};

private:
	union {
		int i_value;
		double d_value;
		std::string s_value;
		bool b_value;
	};

	attr_type type;
	std::string name;
	bool html_attr;

	void setType(int value)          { type = type_int; }
	void setType(double value)       { type = type_double; }
	void setType(const char * value) { type = type_string; }
	void setType(bool value)         { type = type_bool; }

public:
	Attribute() : type(type_null), name("") { };
	template <typename T>
	Attribute(const char *name, T value) : type(type_null), name(name) {
		setValue(value);
	}
	Attribute(const char *name)	: type(type_null), name(name) { }

	void setValue(int value)          { i_value = value; setType(value); }
	void setValue(double value)       { d_value = value; setType(value); }
	void setValue(const char * value) { std::string val(value); s_value = val; setType(value); }
	void setValue(bool value)         { b_value = value; setType(value); }

	int         getIValue() { return i_value; }
	double      getDValue() { return d_value; }
	const char *getSValue() { return s_value.c_str(); };
	bool        getBValue() { return b_value; };

	std::string getValue();
	Attribute::attr_type getType();
	void setName(const char *name);
	std::string getName();

	template <typename T>
	void operator= (T value) {
		setValue(value);
	}

	void setHtml() {
		html_attr = true;
	}
	bool isHtml() {
		return html_attr;
	}

	bool useQuotationMark();
	bool useHtmlMark();
};


#endif //BACHELOR_ATTRIBUTE_H
