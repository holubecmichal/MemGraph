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
	void parseSubgraphs(Agraph_t *g, GraphComponent *g_component);
	void parseNodes(Agraph_t *g, GraphComponent *g_component);
	void parseNodeAttrs(Agnode_t *n, Node *node);
	void parseEdges(Agraph_t *g, GraphComponent *g_component);
	void parseEdgeAttrs(Agedge_t *e, Edge *edge);
	void parseGraphAttrs(Agraph_t *g, GraphComponent *g_component);

	template <typename T, typename U>
	bool isWalkedObject(T *object, U *map) {
		for(auto i : *map) {
			if(i == object) {
				return true;
			}
		}

		return false;
	}

	bool isWalkedObjectAttr(string_map *attrs, std::string name, std::string value);

	void backup(string_map *storage, string_map *walked_attrs);
	void restore(string_map *storage, string_map *walked_attrs);

public:
	GraphvizPlotter() : Plotter(), g_graph(NULL), path("./"), name("graph"), output_format(PNG) {
		setAvailableAttrs();
	}

	GraphvizPlotter(Graph *graph) : Plotter(graph), g_graph(NULL), path("./"), name("graph"), output_format(PNG) {
		setAvailableAttrs();
	}


	virtual ~GraphvizPlotter() {
		if(g_graph != NULL) {
			agclose(g_graph);
		}
	}

	std::string getDot();
	void plot();
	void setOutputFormat(GraphvizPlotter::output format);
	void setOutputPath(const char *path);
	void setOutputName(const char *name);
	Graph *parseDot(const char *content);

};

#endif //BACHELOR_GRAPHVIZPLOTTER_H
