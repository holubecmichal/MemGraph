/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 15.02.16.
//

#ifndef MEMGRAPH_ATTRIBUTE_H
#define MEMGRAPH_ATTRIBUTE_H


#include <string>
#include <utility>
#include <iostream>
#include <map>

namespace memgraph {
	class Attribute {
	public:
		// enum typ, drzi typy atributu
		enum attr_type {
			type_null,
			type_int,
			type_double,
			type_string,
			type_bool
		};

	private:
		// hodnota atributu
		union {
			int i_value;
			double d_value;
			bool b_value;
		};

		/**
		 * hodnota atributu v pripade, ze se jedna o string
		 * v pripade zahrnuti stringu do union => segmentation fault, proto mimu union
		 */
		std::string s_value;

		// typ atributu
		attr_type type;
		// nazev atributu
		std::string name;
		// udava, zda atribut je typu HTML
		bool html_attr = false;
		// udava, zda byl atribut vymazan
		bool removed = false;

	public:
		template <typename T>
		Attribute(std::string name, T value) : type(type_null), name(name), html_attr(false) {
			setValue(value);
		}
		Attribute(std::string name)	: type(type_null), name(name), html_attr(false) { }

		/**
		 * nastavuje hodnotu a typ atributu
		 * @param int|double|const char *|bool|std::string
		 */
		void setValue(int value)          { i_value = value; type = type_int; removed = false; }
		void setValue(double value)       { d_value = value; type = type_double; removed = false; }
		void setValue(const char * value) { std::string val(value); s_value = val; type = type_string; removed = false; }
		void setValue(bool value)         { b_value = value; type = type_bool; removed = false; }
		void setValue(std::string value)  { s_value = value; type = type_string; removed = false; }

		/**
		 * vraci hodnotu atributu
		 * @return int|double|const char*|bool value
		 */
		int         getIValue() { return i_value; }
		double      getDValue() { return d_value; }
		const char *getSValue() { return s_value.c_str(); };
		bool        getBValue() { return b_value; };

		/**
		 * vraci hodnotu atributu
		 * @return std::string value
		 */
		std::string getValue();

		/**
		 * vraci typ atributu
		 * @return attr_type
		 */
		Attribute::attr_type getType();

		/**
		 * nastavi jmeno atributu
		 * @param std::string name
		 */
		void setName(std::string name);

		/**
		 * vraci jmeno atributu
		 * @return std::string
		 */
		std::string getName();

		/**
		 * prirazeni hodnoty atributu pres operator "="
		 * @param typename T
		 */
		template <typename T>
		void operator= (T value) {
			setValue(value);
		}

		/**
		 * nastavi atribut jako HTML
		 */
		void setHtml() {
			html_attr = true;
		}

		/**
		 * @return bool
		 */
		bool isHtml() {
			return html_attr;
		}

		/**
		 * nastavi priznak vymazaneho atributu
		 */
		void remove() {
			removed = true;
		}

		/**
		 * @return bool
		 */
		bool isRemoved() {
			return removed;
		}

		/**
		 * @return bool
		 */
		bool useQuotationMark();

		/**
		 * @return bool
		 */
		bool useHtmlMark();
	};
}


#endif //MEMGRAPH_ATTRIBUTE_H
