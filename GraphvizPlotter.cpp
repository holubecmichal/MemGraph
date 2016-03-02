//
// Created by Michael Holubec on 02.03.16.
//

#include "GraphvizPlotter.h"

const char *GraphvizPlotter::getDot() {
	std::string dot = "";

	dot += dotGraphHeader();
	dot += "{" + new_line;

	dot += dotNodes();
	dot += dotEdges();
	// todo dodelat edges
	// todo pridat subgraphs
	// todo pridat atributy grafu

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

const char *GraphvizPlotter::dotNodes() {
	std::string text = "";
	std::string node = "";
	nodes_map *nodes = graph->getNodes();

	for(nodes_it it = nodes->begin(); it != nodes->end(); ++it) {
		node = std::string(it->second->getName()) + " " + std::string(dotNodeAttributes(it->second));
		node += ";\n";

		text += node;
	}

	return text.c_str();
}

const char *GraphvizPlotter::dotEdges() {
	std::string text = "";
	std::string edge = "";
	edges_vect *edges = graph->getEdges();

	for(edges_it it = edges->begin(); it != edges->end(); ++it) {
		Edge *e = (*it);
		// todo pridat edge atributy
		edge = std::string(e->getFrom()->getName()) + " -> " + std::string(e->getTo()->getName());
		edge += ";\n";

		text += edge;
	}

	return text.c_str();
}

const char *GraphvizPlotter::dotNodeAttributes(Node *node) {
	if(node->attrs.size() == 0) {
		return "";
	}

	attributes_it it = node->attrs.begin();

	std::string attributes = "[";
	while ( true ) {
		attributes += dotAttribute(it->first, it->second);

		if(++it == node->attrs.end()) {
			break;
		}

		attributes += ",";
	}
	attributes += "]";

	return attributes.c_str();
}

const char *GraphvizPlotter::dotAttribute(const char *name, Attribute *attr) {
	std::string attribute = "";
	std::string str_name = name;
	std::string value = attr->getValue();

	attribute += name;
	attribute += "=";

	if(str_name.compare("label") == 0) {
		attribute += "\"";
		attribute += value;
		attribute += "\"";
	} else {
		attribute += value;
	}

	return attribute.c_str();
}

const char *GraphvizPlotter::getIdent() {
	std::string text = "";

	for(int i = 0; i < ident_step; i++) {
		text += tab;
	}

	return text.c_str();
}

void GraphvizPlotter::plot(const char *file_name) {

}

void GraphvizPlotter::setOutputFormat() {

}
