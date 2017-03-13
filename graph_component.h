/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 21.02.16.
//

#ifndef MEMGRAPH_GRAPHCOMPONENT_H
#define MEMGRAPH_GRAPHCOMPONENT_H


#include <vector>
#include "node.h"
#include "edge.h"
#include <typeinfo>

namespace memgraph {
	class Subgraph;

	typedef std::map<std::string, Subgraph *> subgraphs_map;
	typedef subgraphs_map::iterator subgraphs_it;
	typedef std::pair<std::string, Subgraph *> subgraphs_pair;
	typedef std::vector<Subgraph *> subgraphs_vect;

	class GraphComponent {
	private:
		// mnozina vrcholu grafu
		nodes_map nodes;
		// mnozina hran grafu
		edges_vect edges;
		// mnozina pografu grafu
		subgraphs_map subgraphs;
		// atributy vrcholu grafu
		Attributes node_attrs;
		// atributy hran grafu
		Attributes edge_attrs;

		/**
		 * metoda pro vlozeni hrany do mnoziny hran
		 * @param Edge *edge ukazatel na vkladanou hranu
		 */
		void insertEdge(Edge *edge);

		/**
		 * kontroluje, zda ukazatel na objekt neni ukazatelem na NULL
		 * @param typename T object objekt
		 */
		template<typename T>
		void checkNullObject(T *object) {
			if (object == NULL) {
				throw "Type of " + std::string(typeid(T).name()) + " - object is NULL";
			}
		}

		/**
		 * pomocna metoda pro destruktor komponenty grafu
		 * @param subgraphs_map *subgraphs mnozina podgrafu
		 */
		static void destructSubgraphs(subgraphs_map *subgraphs);

	protected:
		// ukazatel na rodice grafu
		GraphComponent *parent = NULL;

		/**
		 * pomocna metoda pro nalezeni vrcholu v podgrafech
		 * @param std::string name nazev vrchol
		 */
		Node *getNodeInSubgraphs(std::string name);

		/**
		 * pomocna metoda pro nalezeni vrcholu v podgrafech
		 * @param std::string name nazev vrchol
		 */
		Node *getLocalNode(std::string name);

		/**
		 * vraci root celeho grafu
		 */
		GraphComponent *getMainParent();

		/**
		 * udrzuje dostupne atributy grafu
		 */
		static string_vector available_attrs;

		/**
		 * pomocna metoda pro vypis upozorneni neexistence atributu grafu ve staticke promenne available_attrs
		 * @param std::string nazev vlozeneho atributu
		 */
		static void printWarning(std::string name);

		/**
		 * kontroluje existenci atributu ve staticke promenne available_attrs
		 * @param std::string nazev vlozeneho atributu
		 */
		static bool isAvailableAttr(std::string name);

	public:
		// mnozina atributu grafu
		Attributes attrs;
		// umoznuje vypnuti vypisu upozorneni na neexistenci atributu v hranach, grafech i vrcholech
		static bool enable_warnings;

		~GraphComponent() {
			destructSubgraphs(&subgraphs);

			for (auto i : nodes) {
				Node *node = i.second;
				delete node;
			}

			for (auto edge : edges) {
				delete edge;
			}
		}

		// ===== GRAPH_COMPONENT METHODS =====
		/**
		 * nastaveni atributu grafu
		 * @param Attributes *new_attrs atributy
		 */
		void setAttrs(Attributes *new_attrs);

		/**
		 * nastaveni atributu grafu
		 * @param Attribute *attr ukazatel na atribut
		 * @return GraphComponent*
		 */
		GraphComponent *setAttr(Attribute *attr) {
			checkAttr(attr->getName());
			attrs.setAttr(attr);
			return this;
		}

		/**
		 * nastaveni atributu grafu
		 * @param std::string name identifikator
		 * @param typename T value hodnota
		 * @return GraphComponent*
		 */
		template<typename T>
		GraphComponent *setAttr(std::string name, T value) {
			checkAttr(name);
			attrs.setAttr(name, value);
			return this;
		}

		/**
		 * nastaveni atributu grafu a jeho oznaceni za HTML
		 * @param std::string name identifikator
		 * @param typename T value hodnota
		 * @return GraphComponent*
		 */
		template<typename T>
		GraphComponent *setHtmlAttr(std::string name, T value) {
			checkAttr(name);
			attrs.setHtmlAttr(name, value);
			return this;
		}

		// ===== SUBGRAPHS METHODS ======
		/**
		 * prida podgraf
		 * @param std::string name nazev podgrafu
		 * @return Subgraph* ukazatel na instanci Subgraph
		 */
		Subgraph *addSubgraph(std::string name);

		/**
		 * vrati komponentu podgrafu
		 * @param std::string name nazev hledaneho podgrafu
		 * @return Subgraph*|NULL
		 */
		Subgraph *getSubgraph(std::string name);

		// ===== NODES METHODS =====
		/**
		 * prida vrchol do komponenty grafu
		 * @param std::string name nazev vrcholu
		 * @return Node* ukazatel na instanci Node
		 */
		Node *addNode(std::string name);

		/**
		 * prida vrchol do komponenty grafu
		 * @param Node *node ukazatel na instanci Node
		 * @return Node* ukazatel na instanci Node
		 */
		Node *addNode(Node *node);

		/**
		 * vrati vrchol, ktery vyhledava v celem prostoru grafu
		 * @param std::string name nazev vrcholu
		 * @return Node*|NULL
		 */
		Node *getNode(std::string name);

		// metoda urcena pouze pro prekladac
		Node *getNode(Node *node) {
			return node;
		}

		// ===== EDGES METHODS =====
		/**
		 * prida hranu do komponenty grafu
		 * @param Edge *edge ukazatel na instanci hrany
		 * @return Edge*
		 */
		Edge *addEdge(Edge *edge);

		/**
		 * vytvori a prida hranu do komponenty grafu
		 * @param std::string from nazev vrcholu
		 * @param std::string to nazev vrcholu
		 * @return Edge*
		 */
		Edge *addEdge(std::string from, std::string to);

		/**
		 * vytvori a prida hranu do komponenty grafu
		 * @param Node *from ukazatel na instanci Node
		 * @param Node *to ukazatel na instanci Node
		 * @return Edge*
		 */
		Edge *addEdge(Node *from, Node *to);

		/**
		 * vyhleda a vrati ukazatel na instanci hrany podle vrcholu
		 * @param Node *from
		 * @param Node *to
		 * @return Edge*
		 */
		Edge *getEdge(Node *from, Node *to);

		/**
		 * vyhleda a vrati ukazatel na instanci hrany podle vrcholu
		 * @param std::string from nazev vrcholu
		 * @param std::string to nazev vrcholu
		 * @return Edge*
		 */
		Edge *getEdge(std::string from, std::string to);

		// ===== NODE ATTRIBUTES METHODS =====
		/**
		 * nastaveni defaultniho atributu pro vrcholy komponenty grafu
		 * @param std::string name identifikator
		 * @param typename T hodnota
		 */
		template<typename T>
		void setNodeAttr(std::string name, T value) {
			Node::checkAttr(name);
			node_attrs.setAttr(name, value);
		}

		/**
		 * nastaveni defaultniho atributu pro vrcholy komponenty grafu
		 * @param Attribute *attr
		 */
		void setNodeAttr(Attribute *attr);

		/**
		 * nastaveni defaultni mnoziny atributu pro vrcholy komponenty grafu
		 * @param Attributes *attrs
		 */
		void setNodeAttrs(Attributes *attrs);

		// ===== EDGE ATTRIBUTES METHODS =====
		/**
		 * nastaveni defaultniho atributu pro vrcholy komponenty grafu
		 * @param std::string name identifikator
		 * @param typename T hodnota
		 */
		template<typename T>
		void setEdgeAttr(std::string name, T value) {
			Edge::checkAttr(name);
			edge_attrs.setAttr(name, value);
		}

		/**
		 * nastaveni defaultniho atributu pro hrany komponenty grafu
		 * @param Attribute *attr
		 */
		void setEdgeAttr(Attribute *attr);

		/**
		 * nastaveni defaultni mnoziny atributu pro hrany komponenty grafu
		 * @param Attributes *attrs
		 */
		void setEdgeAttrs(Attributes *attrs);

		// ===== OTHERS =====
		/**
		 * vraci mnozinu vrcholu komponenty grafu
		 * @return nodes_map*
		 */
		nodes_map *getNodes() { return &nodes; }

		/**
		 * vraci mnozinu hran komponenty grafu
		 * @return edges_vect*
		 */
		edges_vect *getEdges() { return &edges; }

		/**
		 * vraci mnozinu podgrafu komponenty grafu
		 * @return subgraphs_map*
		 */
		subgraphs_map *getSubgraphs() { return &subgraphs; }

		/**
		 * vraci mnozinu defaultnich atributu vrcholu komponenty grafu
		 * @return Attributes*
		 */
		Attributes *getNodeAttrs() { return &node_attrs; }

		/**
		 * vraci mnozinu defaultnich atributu hran komponenty grafu
		 * @return Attributes*
		 */
		Attributes *getEdgeAttrs() { return &edge_attrs; }

		/**
		 * vraci mnozinu atributu komponenty grafu
		 * @return Attributes*
		 */
		Attributes *getAttrs() { return &attrs; }

		/**
		 * vraci atribut komponenty grafu
		 * @return Attribute*
		 */
		Attribute *getAttr(std::string name) { return attrs.getAttr(name); }

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

	};

	class Subgraph : public GraphComponent {
	private:
		std::string name;

	public:
		Subgraph(GraphComponent *parent) { this->parent = parent; };

		Subgraph(GraphComponent *parent, std::string name) {
			this->parent = parent;
			this->name = name;
		}

		/**
		 * vraci identifikator podgrafu
		 * @return const char *
		 */
		const char *getName();

		/**
		 * nastavi identifikator podgrafu
		 * @param std::string value
		 */
		void setName(std::string value);
	};
}


#endif //MEMGRAPH_GRAPHCOMPONENT_H
