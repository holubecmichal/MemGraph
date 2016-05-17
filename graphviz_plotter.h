/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU GPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 02.03.16.
//

#ifndef MEMGRAPH_GRAPHVIZPLOTTER_H
#define MEMGRAPH_GRAPHVIZPLOTTER_H


#include <graphviz/cgraph.h>
#include "plotter.h"
#include "graphviz_attrs.h"

namespace memgraph {
	typedef std::map<std::string, std::string> string_map;

	// pomocna struktura k ucelum transformace struktury graphvizu do interni datove reprezentace
	typedef struct {
		string_map graph_attrs;
		string_map node_attrs;
		string_map edge_attrs;
		std::vector<Agedge_t *> edges;
		std::vector<Agnode_t *> nodes;
	} processedProperties;

	class GraphvizPlotter : public Plotter {
	public:
		// moznosti grafickeho vystupu
		enum output {
			PDF,
			PLAIN,
			PNG,
			PS,
			PS2,
			SVG
		};

	private:
		// vystup grafu - defaultne png
		GraphvizPlotter::output output_format = PNG;
		// cesta vystupu - defaultne aktualni slozka
		std::string path = "./";
		// nazev grafu
		std::string name = "graph";

		/**
		 * vraci typ vystupu
		 * @return std::string
		 */
		std::string getStringOutputFormat();

		/**
		 * vola prislusne metody pro nastaveni povolenych atributu hrany, vrcholu a grafu
		 */
		void setAvailableAttrs() {
			Node::setAvailableAttrs(GraphvizAttrs::node_attrs);
			Edge::setAvailableAttrs(GraphvizAttrs::edge_attrs);
			GraphComponent::setAvailableAttrs(GraphvizAttrs::graph_attrs);
		}

		// grafova struktura knihovny graphviz
		Agraph_t *g_graph = NULL;

		// ===== PARSE DOT METHODS ======
		/**
		 * metoda vola prislusne metody pro transforvani vnitrni struktury graphvizu
		 */
		void parse();

		/**
		 * metoda pro transformaci podgrafu a jeho vrcholu, hran a atributu
		 * @param Agraph_t *g graf|podgraf
		 * @param GraphComponent *g_component komponenta grafu, do ktere se ulozi transformace
		 * @param processedProperties *props zpracovane komponenty, ktere se v dane iteraci preskoci
		 */
		void parseSubgraphs(Agraph_t *g, GraphComponent *g_component, processedProperties *props);

		/**
		 * metoda pro transformaci vrcholu grafu
		 * @param Agraph_t *g graf|podgraf
		 * @param GraphComponent *g_component komponenta grafu, do ktere se ulozi transformace
		 * @param processedProperties *props zpracovane komponenty, ktere se v dane iteraci preskoci
		 */
		void parseNodes(Agraph_t *g, GraphComponent *g_component, processedProperties *props);

		/**
		 * metoda pro transformaci atributu vrcholu grafu
		 * @param Agnode_t *n graphviz vrchol
		 * @param Node *node vrchol interni struktury
		 * @param processedProperties *props zpracovane komponenty, ktere se v dane iteraci preskoci
		 */
		void parseNodeAttrs(Agnode_t *n, Node *node, processedProperties *props);

		/**
		 * metoda pro transformaci hran grafu
		 * @param Agraph_t *g graf|podgraf
		 * @param GraphComponent *g_component komponenta grafu, do ktere se ulozi transformace
		 * @param processedProperties *props zpracovane komponenty, ktere se v dane iteraci preskoci
		 */
		void parseEdges(Agraph_t *g, GraphComponent *g_component, processedProperties *props);

		/**
		 * metoda pro transformaci atributu hrany grafu
		 * @param Agedge_t *e graphviz vrchol
		 * @param Edge *edge hrana interni struktury
		 * @param processedProperties *props zpracovane komponenty, ktere se v dane iteraci preskoci
		 */
		void parseEdgeAttrs(Agedge_t *e, Edge *edge, processedProperties *props);

		/**
		 * metoda pro transformaci atributu hrany grafu
		 * @param Agraph_t *g graphviz graf
		 * @param GraphComponent *g_component komponenta grafu interni struktury
		 * @param processedProperties *props zpracovane komponenty, ktere se v dane iteraci preskoci
		 */
		void parseGraphAttrs(Agraph_t *g, GraphComponent *g_component, processedProperties *props);

		/**
		 * metoda, ktera kontroluje, jestli se jedna jiz o zpracovanou komponentu
		 * @param typename T kontrolovana komponenta
		 * @param typename U mnozina zpracovanych komponent daneho typu
		 * @return bool
		 */
		template<typename T, typename U>
		bool isWalkedObject(T *object, U *map) {
			for (auto i : *map) {
				if (i == object) {
					return true;
				}
			}

			return false;
		}

		/**
		 * metoda, ktera kontroluje, jestli se jedna jiz o zpracovany atribut komponenty
		 * @param string_map *attrs mnozina zpracovanych atributu dane komponenty
		 * @param std::string name identifikator atributu
		 * @param std::string value hodnota atributu
		 * @return bool
		 */
		bool isWalkedObjectAttr(string_map *attrs, std::string name, std::string value);

	public:
		GraphvizPlotter() {
			setAvailableAttrs();
		}

		GraphvizPlotter(Graph *graph) : Plotter(graph) {
			setAvailableAttrs();
		}


		~GraphvizPlotter() {
			if (g_graph != NULL) {
				agclose(g_graph);
			}
		}

		/**
		 * metoda se postara o graficky vystup datoveho modelu
		 */
		void plot();

		/**
		 * nastaveni vystupniho formatu grafu
		 * @param GraphvizPlotter::output format
		 */
		void setOutputFormat(GraphvizPlotter::output format);

		/**
		 * nastaveni cesty vytupu grafu
		 * @param std::string path
		 */
		void setOutputPath(std::string path);

		/**
		 * nastaveni nazvu souboru grafu
		 * @param std::string name
		 */
		void setOutputName(std::string name);

		/**
		 * metoda pro prevod struktury DOT do datoveho modelu knihovny
		 * @param std::string struktura grafu v DOT
		 */
		Graph *parseDot(std::string content);

	};
}

#endif //MEMGRAPH_GRAPHVIZPLOTTER_H
