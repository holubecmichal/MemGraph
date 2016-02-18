//
// Created by Michael Holubec on 15.02.16.
//

#ifndef BACHELOR_ATTRIBUTE_H
#define BACHELOR_ATTRIBUTE_H


#include <string>
#include <utility>
#include <iostream>

enum attr_type {
	type_null,
	type_int,
	type_double,
	type_string,
	type_bool
};

class attribute{
private:
	int i_value_;
	double d_value_;
	std::string s_value_;
	bool b_value_;

	attr_type type;

	void setType(int value) { type = type_int; }
	void setType(double value) { type = type_double; }
	void setType(const char * value) { type = type_string; }
	void setType(bool value) { type = type_bool; }

	void init() {
		type = type_null;
		i_value_ = 0;
		d_value_ = 0;
		s_value_ = "";
		b_value_ = false;
	}

public:
	const int &i_value;
	const double &d_value;
	const std::string &s_value;
	const bool &b_value;

	attribute() : i_value(i_value_), d_value(d_value_), s_value(s_value_), b_value(b_value_) {
		init();
	};

	template <typename T>
	attribute(T value) : i_value(i_value_), d_value(d_value_), s_value(s_value_), b_value(b_value_) {
		setValue(value);
	}

	void setValue(int value) { init(); i_value_ = value; setType(value); }
	void setValue(double value) { init(); d_value_ = value; setType(value); }
	void setValue(const char * value) { init();	s_value_ = value; setType(value); }
	void setValue(bool value) { init();	b_value_ = value; setType(value); }

//	attr_type getType()
};


#endif //BACHELOR_ATTRIBUTE_H
