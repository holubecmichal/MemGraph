//
// Created by Michael Holubec on 02.03.16.
//

#ifndef BACHELOR_GRAPHVIZPLOTTER_H
#define BACHELOR_GRAPHVIZPLOTTER_H


#include <graphviz/cgraph.h>
#include "plotter.h"
#include "graphviz_attrs.h"

typedef std::map<std::string,std::string> string_map;

class GraphvizPlotter : public Plotter {
public:
	enum output {
		PDF,
		PLAIN,
		PNG,
		PS,
		PS2,
		SVG
	};

private:
	GraphvizPlotter::output output_format;
	std::string path;
	std::string name;

	const char *print(std::string *content);
	std::string getIdent();
	std::string dotGraphHeader();
	std::string dotAttribute(std::string name, Attribute *attr);
	std::string dotNodes(nodes_map *nodes);
	std::string dotEdges(edges_vect *edges);
	std::string dotSubgraphs(subgraphs_map *subgraphs);
	std::string dotSubgraph(Subgraph *subgraph);
	std::string dotEdgeType();
	std::string dotGraphAttrs(Attributes *attrs);
	std::string dotGraphNodeAttrs(Attributes *attrs);
	std::string dotGraphEdgeAttrs(Attributes *attrs);
	std::string dotAttributes(Attributes *attrs);
	std::string getStringOutputFormat();

	void setAvailableAttrs() {
		Node::setAvailableAttrs(GraphvizAttrs::node_attrs);
		Edge::setAvailableAttrs(GraphvizAttrs::edge_attrs);
		GraphComponent::setAvailableAttrs(GraphvizAttrs::graph_attrs);
	}

	// ===== PARSE DOT METHODS ======
	Agraph_t *g_graph;
	std::vector<Agedge_t *> walked_edges;
	std::vector<Agnode_t *> walked_nodes;
	string_map walked_graph_attrs;
	string_map walked_node_attrs;
	string_map walked_edge_attrs;

	void parse();
	void parseSubgraphs(Agraph_t *g);
	void parseNodes(Agraph_t *g, GraphComponent *g_component);
	void parseNodeAttrs(Agnode_t *n, Node *node);
	void parseEdges(Agraph_t *g, GraphComponent *g_component);
	void parseEdgeAttrs(Agedge_t *e, Edge *edge);
	void parseGraphAttrs(Agraph_t *g, GraphComponent *g_component);
	bool isWalkedEdge(Agedge_t *e);
	bool isWalkedNode(Agnode_t *n);
	bool isWalkedGraphAttr(std::string name, std::string value);
	bool isWalkedNodeAttr(std::string name, std::string value);
	bool isWalkedEdgeAttr(std::string name, std::string value);
	void backupWalkedNodeAttrs(string_map *storage);
	void backupWalkedEdgeAttrs(string_map *storage);
	void backupWalkedGraphAttrs(string_map *storage);
	void loadWalkedNodeAttrs(string_map *storage);
	void loadWalkedEdgeAttrs(string_map *storage);
	void loadWalkedGraphAttrs(string_map *storage);

public:
	GraphvizPlotter() : Plotter() {
		setAvailableAttrs();
	}

	GraphvizPlotter(Graph *graph) : Plotter(graph) {
		setAvailableAttrs();
	}

	std::string getDot();
	void plot();
	void setOutputFormat(GraphvizPlotter::output format);
	void setOutputPath(const char *path);
	void setOutputName(const char *name);
	Graph *parseDot(const char *content);

};

#endif //BACHELOR_GRAPHVIZPLOTTER_H
