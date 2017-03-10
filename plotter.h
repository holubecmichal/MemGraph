/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 02.03.16.
//

#ifndef MEMGRAPH_PLOTTER_H
#define MEMGRAPH_PLOTTER_H


#include "graph.h"

namespace memgraph {
	const std::string new_line = "\n";
	const std::string tab = "\t";

	class Plotter {
	private:
		/**
		 * vraci pocet tabulatoru, tj velikost odsazeni struktury ve vyslednem textu
		 * @return std::string mnozina tabulatoru
		 */
		std::string getIdent();

		/**
		 * tvori hlavicku grafu
		 * @return std::string
		 */
		std::string dotGraphHeader();

		/**
		 * tvori atribut jakekoli komponenty
		 * @return std::string
		 */
		std::string dotAttribute(std::string name, Attribute *attr);

		/**
		 * tvori vrcholy grafu a podgrafu
		 * @return std::string
		 */
		std::string dotNodes(nodes_map *nodes);

		/**
		 * tvori hrany grafu a podgrafu
		 * @return std::string
		 */
		std::string dotEdges(edges_vect *edges);

		/**
		 * zpracovava podgrafy a jejich komponenty
		 * @return std::string
		 */
		std::string dotSubgraphs(subgraphs_map *subgraphs);

		/**
		 * tvori komponentu podgrafu
		 * @return std::string
		 */
		std::string dotSubgraph(Subgraph *subgraph);

		/**
		 * pomocna metoda pro tvorbu hran - orientovane|neorientovate
		 * @return std::string
		 */
		std::string dotEdgeType();

		/**
		 * zpracuje vsechny atributy grafu a podgrafu
		 * @return std::string
		 */
		std::string dotGraphAttrs(Attributes *attrs);

		/**
		 * zpracuje vsechny defaultni atributy vrcholu grafu
		 * @return std::string
		 */
		std::string dotGraphNodeAttrs(Attributes *attrs);

		/**
		 * zpracuje vsechny defaultni atributy hran grafu
		 * @return std::string
		 */
		std::string dotGraphEdgeAttrs(Attributes *attrs);

		/**
		 * zpracuje vsechny predane atributy
		 * @return std::string
		 */
		std::string dotAttributes(Attributes *attrs);

	public:
		// grafova struktura ke zpracovani
		Graph *graph = NULL;
		// odsazeni komponenty
		int ident_step = 0;

		Plotter(Graph *graph) : graph(graph) { }

		Plotter() { graph = new Graph; }


		virtual ~Plotter() {
			if (graph != NULL) {
				delete graph;
			}
		}

		/**
		 * vraci strukturu grafu v DOT formatu
		 * @return std::string
		 */
		std::string getDot();

		/**
		 * vykresleni grafu
		 */
		virtual void plot() = 0;

		/**
		 * nastaveni cesty vystupu
		 * @param std::string path
		 */
		virtual void setOutputPath(std::string path) = 0;

		/**
		 * nastaveni nazvu grafu urceneho k vystupu
		 * @param std::string name
		 */
		virtual void setOutputName(std::string name) = 0;

	};
}


#endif //MEMGRAPH_PLOTTER_H
