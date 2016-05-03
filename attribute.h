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
		bool b_value;
	};
	std::string s_value;

	attr_type type;
	std::string name;
	bool html_attr = false;
	bool removed = false;

public:
	Attribute() : type(type_null), name("") { };
	template <typename T>
	Attribute(const char *name, T value) : type(type_null), name(name), html_attr(false) {
		setValue(value);
	}
	Attribute(const char *name)	: type(type_null), name(name), html_attr(false) { }

	void setValue(int value)          { i_value = value; type = type_int; removed = false; }
	void setValue(double value)       { d_value = value; type = type_double; removed = false; }
	void setValue(const char * value) { std::string val(value); s_value = val; type = type_string; removed = false; }
	void setValue(bool value)         { b_value = value; type = type_bool; removed = false; }
	void setValue(std::string value)  { s_value = value; type = type_string; removed = false; }

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
	void remove() {
		removed = true;
	}
	bool isRemoved() {
		return removed;
	}

	bool useQuotationMark();
	bool useHtmlMark();
};


#endif //BACHELOR_ATTRIBUTE_H
