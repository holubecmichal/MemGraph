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

#ifndef MEMGRAPH_ATTRIBUTES_H
#define MEMGRAPH_ATTRIBUTES_H


#include <map>
#include <string>
#include <vector>
#include "attribute.h"

namespace memgraph {
	typedef std::map<std::string, Attribute *> attributes_map;
	typedef attributes_map::iterator attributes_it;
	typedef std::pair<std::string, Attribute *> attributes_pair;

	typedef std::vector<std::string> string_vector;
	typedef string_vector::iterator string_vector_it;

	class Attributes {
	private:
		// mnozina atributu
		attributes_map attrs;

		/**
		 * vlozi atribut do mnoziny
		 * @param std::string name nazev atributu
		 * @param Attribute* ukazatel na atribut
		 * @return Attribtue* ukazatel na novy atribut
		 */
		Attribute *insert(std::string name, Attribute *attr);

		/**
		 * vytvori atribut a nepriradi mu zadnou hodnotu
		 * @param std::string name nazev atributu
		 * @return Attribute* ukazatel na atribut
		 */
		Attribute *setAttr(std::string name);

	public:
		Attributes() { }

		virtual ~Attributes() {
			for (auto i : attrs) {
				Attribute *attr = i.second;
				delete attr;
			}
		}

		/**
		 * podle parametru se pokusi najit atribut v mnozine a vrati ukazatel
		 * @param std::string name nazev hledaneho atributu
		 * @return Attribute*|NULL
		 */
		Attribute *getAttr(std::string name);

		/**
		 * pocet prvku v mnozine
		 * @return unsigne long
		 */
		unsigned long size();

		/**
		 * vraci iterator na zacatek std::map
		 * @return attributes_it
		 */
		attributes_it begin();

		/**
		 * vraci iterator na konec std::map
		 * @return attributes_it
		 */
		attributes_it end();

		/**
		 * odstrani vsechny atributy
		 */
		void clear();

		/**
		 * pokusi se najit atribut a nasledne jej smazat
		 * @param std::string name nazev atributu ke smazani
		 */
		void erase(std::string name);

		/**
		 * nastavi atribut
		 * @param Attribute*
		 * @return Attribute*
		 */
		Attribute *setAttr(Attribute *attr);

		/**
		 * nastavi atribut
		 * @param std::string name identifikator
		 * @param Attribute*
		 * @return Attribute*
		 */
		Attribute *setAttr(std::string name, Attribute *attribute);

		/**
		 * nastavi vice atributu
		 * @param Attributes*
		 */
		void setAttrs(Attributes *attrs);

		/**
		 * nastavi nebo vytvori hodnotu atributu
		 * @param std::string name nazev atributu
		 * @param typename T value hodnot
		 * @param bool null_attr udava, jestli se ma vytvorit atribut bez hodnoty
		 * @return Attribute* ukazatel na atribut
		 */
		template<typename T>
		Attribute *setAttr(std::string name, T value, bool null_attr = false) {
			if(name.length() == 0) {
				throw "identificator is empty";
			}

			Attribute *attr = getAttr(name);

			if (attr != NULL) {
				attr->setValue(value);
			} else if (null_attr) {
				attr = insert(name, new Attribute(name));
			} else {
				attr = insert(name, new Attribute(name, value));
			}

			return attr;
		}

		/**
		 * nastavi atribut a priradi mu priznak HTML
		 * @param std::string name identifikator atributu, ktery chceme vytvorit
		 * @param typename T value hodnota atributu
		 * @return Attribute* ukazatel na atribut
		 */
		template<typename T>
		Attribute *setHtmlAttr(std::string name, T value) {
			if(name.length() == 0) {
				throw "identificator is empty";
			}

			Attribute *attr = setAttr(name, value);
			attr->setHtml();
			return attr;
		}

		Attribute &operator[](std::string name) {
			if(name.length() == 0) {
				throw "identificator is empty";
			}

			Attribute *attr = getAttr(name);

			if (attr == NULL) {
				attr = setAttr(name);
			}

			return *attr;
		}

		/**
		 * vrati mnozinu atributu
		 * @return attributes_map mnozina atributu
		 */
		attributes_map *getAttrs() {
			return &attrs;
		}

	};

}


#endif //MEMGRAPH_ATTRIBUTES_H
