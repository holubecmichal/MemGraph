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

std::string GraphvizPlotter::dotAttribute(std::string name, Attribute *attr) {
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

Graph *GraphvizPlotter::parseDot(const char *content) {
	g_graph = agmemread(content);
	parse();

	return graph;
}

void GraphvizPlotter::parse() {
	parseGraphAttrs(g_graph, graph);
	parseSubgraphs(g_graph);
	parseNodes(g_graph, graph);
	parseEdges(g_graph, graph);
}

void GraphvizPlotter::parseSubgraphs(Agraph_t *g) {
	string_map node_attrs_bak;
	string_map edge_attrs_bak;
	string_map graph_attrs_bak;

	backupWalkedNodeAttrs(&node_attrs_bak);
	backupWalkedEdgeAttrs(&edge_attrs_bak);
	backupWalkedGraphAttrs(&graph_attrs_bak);

	for(Agraph_t *subg = agfstsubg(g_graph); subg; subg = agnxtsubg(subg)) {
		Subgraph *subgraph = graph->addSubgraph(agnameof(subg));
		parseGraphAttrs(subg, subgraph);
		// todo nested subgraphs
//		parseSubgraphs(subg);
		parseNodes(subg, subgraph);
		parseEdges(subg, subgraph);

		walked_graph_attrs.clear();
		walked_node_attrs.clear();
		walked_edge_attrs.clear();
		loadWalkedGraphAttrs(&graph_attrs_bak);
		loadWalkedNodeAttrs(&node_attrs_bak);
		loadWalkedEdgeAttrs(&edge_attrs_bak);
	}
}

void GraphvizPlotter::parseGraphAttrs(Agraph_t *g, GraphComponent *g_component) {
	for (auto i : GraphvizAttrs::graph_attrs) {
		Agsym_t *attr = agattr(g, AGRAPH, (char*)i.c_str(), 0);

		if(attr && strlen(attr->defval) && !isWalkedGraphAttr(i.c_str(), attr->defval)) {
			g_component->setAttr(i.c_str(), attr->defval);
			walked_graph_attrs.insert(std::pair<std::string,std::string>(i, attr->defval));
		}

//		Agsym_t *attr = agattrsym(g, (char*)i.c_str());
//
//		if(attr && strlen(attr->defval) && !isWalkedGraphAttr(attr)) {
//			g_component->setAttr(i.c_str(), attr->defval);
//			walked_graph_attrs.push_back(attr);
//			std::cout << i << " = " << attr->defval << std::endl;
//		}
	}

	for (auto i : GraphvizAttrs::node_attrs) {
		Agsym_t *attr = agattr(g, AGNODE, (char*)i.c_str(), 0);

		if(attr && strlen(attr->defval) && !isWalkedNodeAttr(i.c_str(), attr->defval)) {
			g_component->setNodeAttr(i.c_str(), attr->defval);
			walked_node_attrs.insert(std::pair<std::string,std::string>(i, attr->defval));
		}
	}

	for (auto i : GraphvizAttrs::edge_attrs) {
		Agsym_t *attr = agattr(g, AGEDGE, (char*)i.c_str(), 0);

		if(attr && strlen(attr->defval) && !isWalkedEdgeAttr(i.c_str(), attr->defval)) {
			g_component->setEdgeAttr(i.c_str(), attr->defval);
			walked_edge_attrs.insert(std::pair<std::string,std::string>(i, attr->defval));
		}
	}
}

void GraphvizPlotter::parseNodes(Agraph_t *g, GraphComponent *g_component) {
	Agnode_t *n = agfstnode(g);
	while (n) {
		if(isWalkedNode(n)) {
			n = agnxtnode(g, n);
			continue;
		}

		Node *node = g_component->addNode(agnameof(n));
		parseNodeAttrs(n, node);
		walked_nodes.push_back(n);
		n = agnxtnode(g, n);
	}
}

void GraphvizPlotter::parseNodeAttrs(Agnode_t *n, Node *node) {
	for( auto i : GraphvizAttrs::node_attrs) {
		// todo is value double or bool?
//		char *value = agget(n,(char*)i.c_str());
//
//		if(value && strlen(value) > 0) {
//			std::string str_value = value;
//
//			if(str_value.compare("\\N") != 0) {
//				std::cout << i << " " << value << std::endl;
//				node->setAttr(i.c_str(), value);
//			}
//		}

		char *value = agget(n,(char*)i.c_str());

		if(value && strlen(value) > 0 && !isWalkedNodeAttr(i, value)) {
			node->setAttr(i.c_str(), value);
		}
	}
}

void GraphvizPlotter::parseEdges(Agraph_t *g, GraphComponent *g_component) {
	Agnode_t *from_node = agfstnode(g);
	while (from_node) {

		Agedge_t *e = agfstout(g, from_node);
		while(e != NULL) {
			if(isWalkedEdge(e)) {
				e = agnxtout(g, e);
				continue;
			}
			Agnode_t *to_node = e->node;

			Edge *edge = g_component->addEdge(agnameof(from_node), agnameof(to_node));
			parseEdgeAttrs(e, edge);

			walked_edges.push_back(e);
			e = agnxtout(g, e);
		}

		from_node = agnxtnode(g, from_node);
	}
}

void GraphvizPlotter::parseEdgeAttrs(Agedge_t *e, Edge *edge) {
	for( auto i : GraphvizAttrs::edge_attrs) {
		// todo is value double or bool?
		char *value = agget(e,(char*)i.c_str());

		if(value && strlen(value) > 0 && !isWalkedEdgeAttr(i, value)) {
			edge->setAttr(i.c_str(), value);
		}
	}
}

bool GraphvizPlotter::isWalkedEdge(Agedge_t *e) {
	for(auto i : walked_edges) {
		if(i == e) {
			return true;
		}
	}

	return false;
}

bool GraphvizPlotter::isWalkedNode(Agnode_t *n) {
	for(auto i : walked_nodes) {
		if(i == n) {
			return true;
		}
	}

	return false;
}

bool GraphvizPlotter::isWalkedNodeAttr(std::string name, std::string value) {
	for(auto i : walked_node_attrs) {
		if(i.first == name && i.second == value) {
			return true;
		}
	}

	return false;
}

bool GraphvizPlotter::isWalkedEdgeAttr(std::string name, std::string value) {
	for(auto i : walked_edge_attrs) {
		if(i.first == name && i.second == value) {
			return true;
		}
	}

	return false;
}

bool GraphvizPlotter::isWalkedGraphAttr(std::string name, std::string value) {
	for(auto i : walked_graph_attrs) {
		if(i.first == name && i.second == value) {
			return true;
		}
	}

	return false;
}

void GraphvizPlotter::backupWalkedNodeAttrs(string_map *storage) {
	for(auto i : walked_node_attrs) {
		storage->insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

void GraphvizPlotter::backupWalkedEdgeAttrs(string_map *storage) {
	for(auto i : walked_edge_attrs) {
		storage->insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

void GraphvizPlotter::backupWalkedGraphAttrs(string_map *storage) {
	for(auto i : walked_graph_attrs) {
		storage->insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

void GraphvizPlotter::loadWalkedNodeAttrs(string_map *storage) {
	for( auto i : *storage) {
		walked_node_attrs.insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

void GraphvizPlotter::loadWalkedEdgeAttrs(string_map *storage) {
	for( auto i : *storage) {
		walked_edge_attrs.insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

void GraphvizPlotter::loadWalkedGraphAttrs(string_map *storage) {
	for( auto i : *storage) {
		walked_graph_attrs.insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}
