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

#ifndef MEMGRAPH_EDGE_H
#define MEMGRAPH_EDGE_H


#include <vector>
#include "node.h"
#include "attributes.h"

namespace memgraph {
	class Edge {
	private:
		Node *from;
		Node *to;
		// dostupne atributy hrany
		static string_vector available_attrs;
		// urcuje, zda je hrana odstranena
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

		Edge(Node *from, Node *to) : from(from), to(to) {
			if(from == NULL || to == NULL) {
				throw "Some node is NULL";
			}
		}

		~Edge() { }

		/**
		 * @param Node*
		 */
		void setFrom(Node *node);

		/**
		 * @param Node*
		 */
		void setTo(Node *node);

		/**
		 * @return Node*
		 */
		Node *getFrom();

		/**
		 * @return Node*
		 */
		Node *getTo();

		/**
		 * vraci atribut hrany
		 * @param std::string name identifikator atributu
		 * @retrun Attribute*|NULL
		 */
		Attribute *getAttr(std::string name);

		/**
		 * nastavi atributy hrany
		 * @param Attributes* ukazatel na mnozinu atributu k vlozeni
		 */
		void setAttrs(Attributes *new_attrs);

		/**
		 * nastavi atribut hrany
		 * @param std::string name identifikator atributu
		 * @param typename T hodnota atributu
		 * @return Edge* ukazatel na hranu
		 */
		template<typename T>
		Edge *setAttr(std::string name, T value) {
			if(name.length() == 0) {
				throw "identificator is empty";
			}

			checkAttr(name);
			attrs.setAttr(name, value);
			return this;
		}

		/**
		 * nastavi atribut hrany
		 * @param Attribute* attr ukazatel na vkladany atribut
		 * @return Edge* ukazatel na hranu
		 */
		Edge *setAttr(Attribute *attr) {
			checkAttr(attr->getName());
			attrs.setAttr(attr);
			return this;
		}

		/**
		 * nastavi atribut hrany a atribut oznaci za HTML
		 * @param std::string name identifikator atributu
		 * @param typename T hodnota atributu
		 * @return Edge* ukazatel na hranu
		 */
		template<typename T>
		Edge *setHtmlAttr(std::string name, T value) {
			if(name.length() == 0) {
				throw "identificator is empty";
			}

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
		 * vraci mnozinu atributu hrany
		 * @return attributes_map mnozina atributu hrany
		 */
		attributes_map *getAttrs() {
			return this->attrs.getAttrs();
		}

		/**
		 * oznaci atribut za odstraneny
		 */
		void remove() {
			removed = true;
		}

		/**
		 * vraci priznak, zda je atribut odstraneny
		 * @return bool
		 */
		bool isRemoved() {
			return removed;
		}

	};

	typedef std::vector<Edge *> edges_vect;
	typedef edges_vect::iterator edges_it;
}

#endif //MEMGRAPH_EDGE_H
