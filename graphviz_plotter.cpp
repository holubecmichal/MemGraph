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

#include "graphviz_plotter.h"
#include "utility.h"
#include <graphviz/gvc.h>
#include <regex>

namespace memgraph {
	void GraphvizPlotter::plot() {
		if(path.length() == 0) {
			throw "Path is empty";
		}

		if(name.length() == 0) {
			throw "Name is empty";
		}

		// nacte nastaveny format grafu
		std::string format = getStringOutputFormat();
		// vytvori konecne umisteni a nazev souboru
		std::string filename = path + name + "." + format;

		// vytvori potrebne struktury graphvizu
		GVC_t *gvc;
		Agraph_t *g;
		gvc = gvContext();

		// parsovani ze struktury DOT do interni reprezentace graphvizu
		g = agmemread(getDot().c_str());

		// pouziti defaultniho nastroje dot
		gvLayout(gvc, g, "dot");
		// vykresleni grafu do souboru
		gvRenderFilename(gvc, g, format.c_str(), filename.c_str());
		// uvolneni vsech struktur graphvizu z pameti
		gvFreeLayout(gvc, g);
		agclose(g);
	}

	void GraphvizPlotter::setOutputFormat(GraphvizPlotter::output format) {
		output_format = format;
	}

	std::string GraphvizPlotter::getStringOutputFormat() {
		std::string format;

		switch (output_format) {
			case PDF:
				format = "pdf";
				break;
			case PLAIN:
				format = "plain";
				break;
			case PNG:
				format = "png";
				break;
			case PS:
				format = "ps";
				break;
			case PS2:
				format = "ps2";
				break;
			case SVG:
				format = "svg";
				break;
			default:
				throw "Unknown format";
		}

		return format;
	}

	void GraphvizPlotter::setOutputPath(std::string path) {
		this->path = path;
	}

	void GraphvizPlotter::setOutputName(std::string name) {
		this->name = name;
	}

	Graph *GraphvizPlotter::parseDot(std::string content) {
		if(content.length() == 0) {
			throw "content is empty";
		}

		g_graph = agmemread(content.c_str());

		if (g_graph) {
			parse();
		}

		return graph;
	}

	void GraphvizPlotter::parse() {
		processedProperties processed_props;

		// zpracovani atributu grafu
		parseGraphAttrs(g_graph, graph, &processed_props);
		// zpracovani podgrafu grafu
		parseSubgraphs(g_graph, graph, &processed_props);
		// zpracovani vrcholu grafu
		parseNodes(g_graph, graph, &processed_props);
		// zpracovani hran grafu
		parseEdges(g_graph, graph, &processed_props);
	}

	void GraphvizPlotter::parseSubgraphs(Agraph_t *g, GraphComponent *g_component, processedProperties *props) {
		// nacteni zpracovanych komponent pro jejich mozne budouci preskoceni v aktualni iteraci
		string_map node_attrs_bak = props->node_attrs;
		string_map edge_attrs_bak = props->edge_attrs;
		string_map graph_attrs_bak = props->graph_attrs;

		// prochazeni vsech podgrafu daneho grafu/podgrafu
		for (Agraph_t *subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
			// vytvoreni podgrafu v datovem modelu
			Subgraph *subgraph = g_component->addSubgraph(agnameof(subg));
			// zpracovani atributu grafu/podgrafu a ulozeni do datoveho modelu k danemu podgrafu
			parseGraphAttrs(subg, subgraph, props);
			// zpracovani podgrafu a ulozeni do datoveho modelu k danemu pdgrafu
			parseSubgraphs(subg, subgraph, props);
			// stejne zpracovani v pripade
			parseNodes(subg, subgraph, props);
			parseEdges(subg, subgraph, props);

			// pro dalsi podgraf nactu zpet zpracovane komponenty
			props->graph_attrs.clear();
			props->node_attrs.clear();
			props->edge_attrs.clear();

			props->graph_attrs = graph_attrs_bak;
			props->node_attrs = node_attrs_bak;
			props->edge_attrs = edge_attrs_bak;
		}
	}

	void GraphvizPlotter::parseGraphAttrs(Agraph_t *g, GraphComponent *g_component, processedProperties *props) {
		// prochazim vsechny mozne atributy grafu
		for (auto i : GraphvizAttrs::graph_attrs) {
			Agsym_t *attr = agattr(g, AGRAPH, (char *) i.c_str(), NULL);

			// pokud je dany atribut grafu k nejakemu grafu prirazen a jeste nebyl zpracovan, priradim jej ke komponente grafu
			if ((attr && !isWalkedObjectAttr(&props->graph_attrs, i.c_str(), attr->defval))) {
				std::string val(attr->defval);
				// pokud se nejdna o html atribut, vyescapujeme uvozovky
				if (!aghtmlstr(attr->defval)) {
					val = Utility::escape_quotes(val);
				}

				// pridani atributu
				g_component->setAttr(i.c_str(), val.c_str());
				// pridani mezi zpracovane komponenty
				props->graph_attrs.insert(std::pair<std::string, std::string>(i, attr->defval));

				// pokud se jedna o html atribut, nastavime priznak
				if (aghtmlstr(attr->defval)) {
					Attribute *g_attr = g_component->attrs.getAttr(i.c_str());
					g_attr->setHtml();
				}
			}
		}

		// prochazim vsechny mozne atributy vrcholu
		for (auto i : GraphvizAttrs::node_attrs) {
			Agsym_t *attr = agattr(g, AGNODE, (char *) i.c_str(), 0);

			// pokud je dany atribut vrcholu k nejakemu grafu prirazen a jeste nebyl zpracovan, priradim jej ke komponente grafu
			if (attr && !isWalkedObjectAttr(&props->node_attrs, i.c_str(), attr->defval)) {
				std::string val(attr->defval);
				// pokud se nejdna o html atribut, vyescapujeme uvozovky
				if (!aghtmlstr(attr->defval)) {
					val = Utility::escape_quotes(val);
				}

				g_component->setNodeAttr(i.c_str(), val.c_str());
				props->node_attrs.insert(std::pair<std::string, std::string>(i, attr->defval));

				if (aghtmlstr(attr->defval)) {
					Attribute *g_attr = g_component->getNodeAttrs()->getAttr(i.c_str());
					g_attr->setHtml();
				}
			}
		}

		// prochazim vsechny mozne atributy vrcholu
		for (auto i : GraphvizAttrs::edge_attrs) {
			Agsym_t *attr = agattr(g, AGEDGE, (char *) i.c_str(), 0);

			// pokud je dany atribut hrany k nejakemu grafu prirazen a jeste nebyl zpracovan, priradim jej ke komponente grafu
			if (attr && !isWalkedObjectAttr(&props->edge_attrs, i.c_str(), attr->defval)) {
				std::string val(attr->defval);
				// pokud se nejdna o html atribut, vyescapujeme uvozovky
				if (!aghtmlstr(attr->defval)) {
					val = Utility::escape_quotes(val);
				}

				g_component->setEdgeAttr(i.c_str(), val.c_str());
				props->edge_attrs.insert(std::pair<std::string, std::string>(i, attr->defval));

				if (aghtmlstr(attr->defval)) {
					Attribute *g_attr = g_component->getEdgeAttrs()->getAttr(i.c_str());
					g_attr->setHtml();
				}
			}
		}
	}

	void GraphvizPlotter::parseNodes(Agraph_t *g, GraphComponent *g_component, processedProperties *props) {
		Agnode_t *n = agfstnode(g);

		// prochazim vsechny vrcholy
		while (n) {
			// pokud byl tento vrchol uz zpracovan, preskocime
			if (isWalkedObject(n, &props->nodes)) {
				n = agnxtnode(g, n);
				continue;
			}

			// pokud vrchol jeste nebyl zpracovan, vytvorime novy vrchol
			Node *node = g_component->addNode(agnameof(n));
			// k tomuto vrcholu pridame i jeho atributy
			parseNodeAttrs(n, node, props);
			// pridame mezi zpracovane
			props->nodes.push_back(n);
			// nacteme dalsi
			n = agnxtnode(g, n);
		}
	}

	void GraphvizPlotter::parseNodeAttrs(Agnode_t *n, Node *node, processedProperties *props) {
		// prochazime vsechny dostupne atributy vrcholu
		for (auto i : GraphvizAttrs::node_attrs) {
			char *value = agget(n, (char *) i.c_str());

			// pokud byl dany atribut zadan a jeste nebyl zpracovan
			if (value && !isWalkedObjectAttr(&props->node_attrs, i, value)) {
				std::string val(value);
				// pokud nejde o html atribut, vyescapujeme uvozovky
				if (!aghtmlstr(value)) {
					val = Utility::escape_quotes(val);
				}

				// nastaveni atributu
				node->setAttr(i.c_str(), val.c_str());

				// pokud jde o html, nastavime priznak
				if (aghtmlstr(value)) {
					Attribute *g_attr = node->getAttr(i.c_str());
					g_attr->setHtml();
				}
			}
		}
	}

	void GraphvizPlotter::parseEdges(Agraph_t *g, GraphComponent *g_component, processedProperties *props) {
		Agnode_t *from_node = agfstnode(g);
		// nacteme prvni vrchol
		while (from_node) {

			// nacteme hranu, ktera z vrcholu vychazi
			Agedge_t *e = agfstout(g, from_node);
			while (e) {
				// pokud byla tato hrana uz zpracovana, preskocime
				if (isWalkedObject(e, &props->edges)) {
					e = agnxtout(g, e);
					continue;
				}
				// nacteme vrchol, ke kteremu hrana vede
				Agnode_t *to_node = e->node;

				// pridame hranu do datoveho modelu
				Edge *edge = g_component->addEdge(agnameof(from_node), agnameof(to_node));
				// pridame vsechny jeho atributy
				parseEdgeAttrs(e, edge, props);

				// pridame mezi zpracovane
				props->edges.push_back(e);
				// nacteme dalsi hranu, ktera vede z daneho vrcholu
				e = agnxtout(g, e);
			}

			// nacteme dalsi vrchol
			from_node = agnxtnode(g, from_node);
		}
	}

	void GraphvizPlotter::parseEdgeAttrs(Agedge_t *e, Edge *edge, processedProperties *props) {
		// prochazime vsechny mozne atributy hrany
		for (auto i : GraphvizAttrs::edge_attrs) {
			char *value = agget(e, (char *) i.c_str());

			// pokud by dany atribut zadan a nebyl jeste zpracovan
			if (value && !isWalkedObjectAttr(&props->edge_attrs, i, value)) {
				std::string val(value);
				// pokud neni atribut html, vyescapujeme hodnotu
				if (!aghtmlstr(value)) {
					val = Utility::escape_quotes(val);
				}

				// pridame atribut k hrane
				edge->setAttr(i.c_str(), val.c_str());

				// pokud je to html, nastavime priznak
				if (aghtmlstr(value)) {
					Attribute *g_attr = edge->getAttr(i.c_str());
					g_attr->setHtml();
				}
			}
		}
	}

	bool GraphvizPlotter::isWalkedObjectAttr(string_map *attrs, std::string name, std::string value) {
		// prochazi mnozinu zpracovanych atributu a vraci, jestli se mezi temito atributy dany atribut nachazi
		for (auto i : *attrs) {
			if (i.first == name && i.second == value) {
				return true;
			}
		}

		return false;
	}
}
