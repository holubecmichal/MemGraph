//
// Created by Michael Holubec on 02.03.16.
//

#include "graphviz_plotter.h"
#include <graphviz/gvc.h>

std::string GraphvizPlotter::getDot() {
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


std::string GraphvizPlotter::dotGraphHeader() {
	std::string text = "";

	if(graph->getType() == digraph) {
		text += "digraph";
	} else {
		text += "graph";
	}

	text += " G ";

	return text;
}

std::string GraphvizPlotter::dotGraphAttrs(Attributes *attrs) {
	std::string text = "";

	if(attrs->size() > 0) {
		attributes_it it = attrs->begin();

		while( true ) {
			text += getIdent() + dotAttribute(it->first, it->second) + ";" + new_line;

			if(++it == attrs->end()) {
				break;
			}

		}
		text += new_line;
	}
	return text;
}

std::string GraphvizPlotter::dotGraphNodeAttrs(Attributes *attrs) {
	std::string text = "";

	if(attrs->size() > 0) {
		text += getIdent() + "node ";
		text += dotAttributes(attrs);
		text += ";" + new_line + new_line;
	}

	return text;
}

std::string GraphvizPlotter::dotGraphEdgeAttrs(Attributes *attrs) {
	std::string text = "";

	if(attrs->size() > 0) {
		text += getIdent() + "edge ";
		text += dotAttributes(attrs);
		text += ";" + new_line + new_line;
	}

	return text;
}

std::string GraphvizPlotter::dotNodes(nodes_map *nodes) {
	std::string text = "";
	std::string node = "";

	for(nodes_it it = nodes->begin(); it != nodes->end(); ++it) {
		if(it->second->attrs.size() > 0) {
			node = getIdent() + std::string(it->second->getName());
			node += " ";
			node += std::string(dotAttributes(&it->second->attrs));
			node += ";" + new_line;
			text += node;
		}
	}

	if(text.length() > 0) {
		text += new_line;
	}
	return text;
}

std::string GraphvizPlotter::dotEdges(edges_vect *edges) {
	std::string text = "";
	std::string edge = "";

	for(edges_it it = edges->begin(); it != edges->end(); ++it) {
		Edge *e = (*it);
		edge = getIdent() + std::string(e->getFrom()->getName()) + dotEdgeType() + std::string(e->getTo()->getName());

		if(e->attrs.size() > 0) {
			edge += " ";
			edge += std::string(dotAttributes(&e->attrs));
		}

		edge += ";" + new_line;
		text += edge;
	}

	return text;
}

std::string GraphvizPlotter::dotEdgeType() {
	if(graph->getType() == std_graph) {
		return " -- ";
	} else if(graph->getType() == digraph) {
		return " -> ";
	}

	throw "Unknown graph type";
}

std::string GraphvizPlotter::dotSubgraphs(subgraphs_map *subgraphs) {
	std::string text = "";

	for(subgraphs_it it = subgraphs->begin(); it != subgraphs->end(); ++it) {
		text += dotSubgraph(it->second);
	}

	return text;
}

std::string GraphvizPlotter::dotSubgraph(Subgraph *subgraph) {
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

std::string GraphvizPlotter::dotAttributes(Attributes *attrs) {
	if(attrs->size() == 0) {
		return "";
	}

	attributes_it it = attrs->begin();

	std::string attributes = "[";
	while ( true ) {
		attributes += dotAttribute(it->first, it->second);

		if(++it == attrs->end()) {
			break;
		}

		attributes += ",";
	}
	attributes += "]";

	return attributes.c_str();
}

std::string GraphvizPlotter::dotAttribute(const char *name, Attribute *attr) {
	std::string attribute = "";
	std::string str_name = name;
	std::string value = attr->getValue();

	attribute += str_name + "=" + value;

	return attribute;
}

std::string GraphvizPlotter::getIdent() {
	std::string text = "";

	for(int i = 0; i < ident_step; i++) {
		text += tab;
	}

	return text;
}

const char *GraphvizPlotter::print(std::string *content) {
	std::string dot = std::string(getIdent()) + *content;
	return dot.c_str();
}

void GraphvizPlotter::plot() {
	std::string format = getStringOutputFormat();
	std::string filename = path + name + "." + format;

	GVC_t *gvc;
	Agraph_t *g;
	gvc = gvContext();

	g = agmemread(getDot().c_str());

	// todo implementovat i jiny layout, nez dot? (neato, xdot, ...)
	gvLayout(gvc, g, "dot");
	gvRenderFilename (gvc, g, format.c_str(), filename.c_str());
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

void GraphvizPlotter::setOutputPath(const char *path) {
	this->path = path;
}

void GraphvizPlotter::setOutputName(const char *name) {
	this->name = name;
}

void GraphvizPlotter::setAvailableAttrs() {

}
