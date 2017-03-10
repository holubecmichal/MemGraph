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

#ifndef MEMGRAPH_NODE_H
#define MEMGRAPH_NODE_H

#include <string>
#include <vector>
#include "attributes.h"
#include "graphviz_attrs.h"

namespace memgraph {
	class Node {
	private:
		// nazev vrcholu
		std::string name = "";
		// mnozina dostupnych atributu
		static string_vector available_attrs;
		bool removed = false;

		/**
		 * pomocna metoda pro vypis upozorneni neexistence atributu hrany ve staticke promenne available_attrs
		 * @param std::string nazev vlozeneho atributu
		 */
		static void printWarning(std::string name);

		/**
		 * kontroluje existenci atributu ve staticke promenne available_attrs
		 * @param std::string nazev vlozeneho atributu
		 */
		static bool isAvailableAttr(std::string name);

	public:
		Attributes attrs;

		Node(std::string name) {
			this->name = name;
		}

		virtual ~Node() { }

		/**
		 * vraci atribut vrcholu
		 * @param std::string name
		 * @return Attribute*
		 */
		Attribute *getAttr(std::string name);

		/**
		 * vraci nazev vrcholu
		 */
		const char *getName();

		/**
		 * nastavuje nazev vrcholu
		 * @param std::string value nazev
		 */
		void setName(std::string value);

		/**
		 * nastavi atributy vrcholu
		 * @param Attributes *new_attrs mnozina atributy k nastaveni
		 * @return Node*
		 *
		 */
		Node *setAttrs(Attributes *new_attrs);

		/**
		 * nastavi atribut vrcholu
		 * @param std::string name identifikator atributu
		 * @param typename T hodnota
		 * @return Node*
		 */
		template<typename T>
		Node *setAttr(std::string name, T value) {
			checkAttr(name);
			attrs.setAttr(name, value);
			return this;
		}

		/**
		 * nastavi atribut vrcholu
		 * @param Attribute* atribut k prirazeni
		 * @return Node*
		 */
		Node *setAttr(Attribute *attr) {
			checkAttr(attr->getName());
			attrs.setAttr(attr);
			return this;
		}

		/**
		 * nastavi html atribut
		 * @param std::string name identifikator
		 * @param typename T hodnota
		 * @return Node*
		 */
		template<typename T>
		Node *setHtmlAttr(std::string name, T value) {
			checkAttr(name);
			attrs.setHtmlAttr(name, value);
			return this;
		}

		/**
		 * kontroluje existenci identifikatoru atributu v mnozine povolenych atributu
		 * @param std::string name identifikator
		 */
		static void checkAttr(std::string name);

		/**
		 * nastavi mnozinu povolenych atributu
		 * @param string_vector attrs mnozina povolenych atributu
		 */
		static void setAvailableAttrs(string_vector attrs) {
			available_attrs = attrs;
		}

		/**
		 * nastavi priznak odstraneni vrcholu ze struktury
		 */
		void remove() {
			removed = true;
		}

		/**
		 * vraci priznak odstraneni
		 */
		bool isRemoved() {
			return removed;
		}

	};

	typedef std::map<std::string, Node *> nodes_map;
	typedef nodes_map::iterator nodes_it;
	typedef std::pair<std::string, Node *> nodes_pair;
	typedef std::vector<Node *> nodes_vect;
}


#endif //MEMGRAPH_NODE_H
