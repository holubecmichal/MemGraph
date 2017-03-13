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

#include "plotter.h"

namespace memgraph {
	std::string Plotter::getDot() {
		std::string dot = "";

		dot += dotGraphHeader();
		dot += "{" + new_line;

		ident_step++;

		dot += std::string(dotGraphAttrs(&graph->attrs));
		dot += std::string(dotGraphNodeAttrs(graph->getNodeAttrs()));
		dot += std::string(dotGraphEdgeAttrs(graph->getEdgeAttrs()));
		dot += std::string(dotNodes(graph->getNodes()));
		dot += std::string(dotSubgraphs(graph->getSubgraphs()));
		dot += std::string(dotEdges(graph->getEdges()));

		ident_step--;

		dot += "}";

		return dot;
	}


	std::string Plotter::dotGraphHeader() {
		std::string text = "";

		if (graph->getType() == digraph) {
			text += "digraph";
		} else {
			text += "graph";
		}

		text += " G ";

		return text;
	}

	std::string Plotter::dotGraphAttrs(Attributes *attrs) {
		std::string text = "";

		if (attrs->size() > 0) {
			for (auto i : *attrs) {
				if (!i.second->isRemoved()) {
					text += getIdent() + dotAttribute(i.first, i.second) + ";" + new_line;
				}
			}
			text += new_line;
		}
		return text;
	}

	std::string Plotter::dotGraphNodeAttrs(Attributes *attrs) {
		std::string text = "";

		if (attrs->size() > 0) {
			text += getIdent() + "node ";
			text += dotAttributes(attrs);
			text += ";" + new_line + new_line;
		}

		return text;
	}

	std::string Plotter::dotGraphEdgeAttrs(Attributes *attrs) {
		std::string text = "";

		if (attrs->size() > 0) {
			text += getIdent() + "edge ";
			text += dotAttributes(attrs);
			text += ";" + new_line + new_line;
		}

		return text;
	}

	std::string Plotter::dotNodes(nodes_map *nodes) {
		std::string text = "";
		std::string node = "";

		for (auto i : *nodes) {
			if (i.second->isRemoved()) continue;

			if (i.second->attrs.size() > 0) {
				node = getIdent() + std::string(i.second->getName());
				node += " ";
				node += std::string(dotAttributes(&i.second->attrs));
				node += ";" + new_line;
				text += node;
			}
		}

		if (text.length() > 0) {
			text += new_line;
		}

		return text;
	}

	std::string Plotter::dotEdges(edges_vect *edges) {
		std::string text = "";
		std::string edge = "";

		for (auto e : *edges) {
			if (e->isRemoved()) continue;

			if (e->getFrom()->isRemoved()) {
				throw "Can't plot edge - from_node was removed";
			}
			if (e->getTo()->isRemoved()) {
				throw "Can't plot edge - to_node was removed";
			}

			edge = getIdent() + std::string(e->getFrom()->getName()) + dotEdgeType() +
			       std::string(e->getTo()->getName());

			if (e->attrs.size() > 0) {
				edge += " ";
				edge += std::string(dotAttributes(&e->attrs));
			}

			edge += ";" + new_line;
			text += edge;
		}

		return text;
	}

	std::string Plotter::dotEdgeType() {
		if (graph->getType() == std_graph) {
			return " -- ";
		} else if (graph->getType() == digraph) {
			return " -> ";
		}

		throw "Unknown graph type";
	}

	std::string Plotter::dotSubgraphs(subgraphs_map *subgraphs) {
		std::string text = "";

		for (subgraphs_it it = subgraphs->begin(); it != subgraphs->end(); ++it) {
			text += dotSubgraph(it->second);
		}

		return text;
	}

	std::string Plotter::dotSubgraph(Subgraph *subgraph) {
		std::string text = "";

		text += getIdent() + "subgraph " + std::string(subgraph->getName()) + " {" + new_line;
		ident_step++;
		text += std::string(dotGraphAttrs(&subgraph->attrs));
		text += std::string(dotGraphNodeAttrs(subgraph->getNodeAttrs()));
		text += std::string(dotGraphEdgeAttrs(subgraph->getEdgeAttrs()));
		text += std::string(dotNodes(subgraph->getNodes()));
		text += std::string(dotSubgraphs(subgraph->getSubgraphs()));
		text += std::string(dotEdges(subgraph->getEdges()));
		ident_step--;
		text += getIdent() + "}" + new_line + new_line;

		return text;
	}

	std::string Plotter::dotAttributes(Attributes *attrs) {
		if (attrs->size() == 0) {
			return "";
		}

		attributes_it it = attrs->begin();

		std::string attributes = "[";
		while (true) {
			if (!it->second->isRemoved()) {
				attributes += dotAttribute(it->first, it->second);
			}

			if (++it == attrs->end()) {
				break;
			}

			if (!it->second->isRemoved()) {
				attributes += ",";
			}
		}
		attributes += "]";

		return attributes.c_str();
	}

	std::string Plotter::dotAttribute(std::string name, Attribute *attr) {
		std::string attribute = "";
		std::string str_name = name;
		std::string value = attr->getValue();

		attribute += str_name + "=" + value;

		return attribute;
	}

	std::string Plotter::getIdent() {
		std::string text = "";

		for (int i = 0; i < ident_step; i++) {
			text += tab;
		}

		return text;
	}
}
