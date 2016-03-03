//
// Created by Michael Holubec on 02.03.16.
//

#include "graphviz_plotter.h"

const char *GraphvizPlotter::getDot() {
	std::string dot = "";

	dot += dotGraphHeader();
	dot += "{" + new_line;

	ident_step++;

	dot += std::string(dotNodes(graph->getNodes()));
	dot += std::string(dotSubgraphs(graph->getSubgraphs()));
	dot += std::string(dotEdges(graph->getEdges()));
	// todo pridat atributy grafu

	ident_step--;

	dot += "}";

	return dot.c_str();
}


const char *GraphvizPlotter::dotGraphHeader() {
	std::string text = "";

	if(graph->getType() == digraph) {
		text += "digraph";
	} else {
		text += "graph";
	}

	text += " Graph ";

	return text.c_str();
}

const char *GraphvizPlotter::dotNodes(nodes_map *nodes) {
	std::string text = "";
	std::string node = "";

	for(nodes_it it = nodes->begin(); it != nodes->end(); ++it) {
		node = getIdent() + std::string(it->second->getName());

		if(it->second->attrs.size() > 0) {
			node += " ";
			node += std::string(dotAttributes(it->second));
		}

		node += ";" + new_line;
		text += node;
	}

	return text.c_str();
}

const char *GraphvizPlotter::dotEdges(edges_vect *edges) {
	std::string text = "";
	std::string edge = "";

	for(edges_it it = edges->begin(); it != edges->end(); ++it) {
		Edge *e = (*it);
		edge = getIdent() + std::string(e->getFrom()->getName()) + " -> " + std::string(e->getTo()->getName());

		if(e->attrs.size() > 0) {
			edge += " ";
			edge += std::string(dotAttributes(e));
		}

		edge += ";" + new_line;
		text += edge;
	}

	return text.c_str();
}

const char *GraphvizPlotter::dotSubgraphs(subgraphs_map *subgraphs) {
	std::string text = "";

	for(subgraphs_it it = subgraphs->begin(); it != subgraphs->end(); ++it) {
		text += dotSubgraph(it->second);
	}

	return text.c_str();
}

const char *GraphvizPlotter::dotSubgraph(Subgraph *subgraph) {
	std::string text = "";

	text += getIdent() + "subgraph " + std::string(subgraph->getName()) + " {" + new_line;
	ident_step++;
	text += std::string(dotNodes(subgraph->getNodes()));
	text += std::string(dotSubgraphs(subgraph->getSubgraphs()));
	text += std::string(dotEdges(subgraph->getEdges()));
	ident_step--;
	text += getIdent() + "}" + new_line;

	return text.c_str();
}

//const char *GraphvizPlotter::dotNodeAttributes(Node *node) {
//	if(node->attrs.size() == 0) {
//		return "";
//	}
//
//	attributes_it it = node->attrs.begin();
//
//	std::string attributes = "[";
//	while ( true ) {
//		attributes += dotAttribute(it->first, it->second);
//
//		if(++it == node->attrs.end()) {
//			break;
//		}
//
//		attributes += ",";
//	}
//	attributes += "]";
//
//	return attributes.c_str();
//}

const char *GraphvizPlotter::dotAttribute(const char *name, Attribute *attr) {
	std::string attribute = "";
	std::string str_name = name;
	std::string value = attr->getValue();

	attribute += name;
	attribute += "=";

	attribute += attr->useQuotationMarks() ? q_mark : "";
	attribute += value;
	attribute += attr->useQuotationMarks() ? q_mark : "";

	return attribute.c_str();
}

std::string GraphvizPlotter::getIdent() {
	std::string text = "";

	for(int i = 0; i < ident_step; i++) {
		text += tab;
	}

	return text.c_str();
}

const char *GraphvizPlotter::print(std::string *content) {
	std::string dot = std::string(getIdent()) + *content;
	return dot.c_str();
}

void GraphvizPlotter::plot(const char *file_name) {

}

void GraphvizPlotter::setOutputFormat() {

}
