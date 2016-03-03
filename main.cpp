#include <iostream>
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"
#include "plotter.h"
#include "graphviz_plotter.h"

using namespace std;

int main() {
//	Graph graph;
	Attributes *attrs;
	Edge *edge;
	Subgraph *subgraph;
	Node *node;
	GraphComponent *graphComponent;

//	subgraph->addNode("asd_1");
//	subgraph->addNode("asd_2");
//	subgraph->addNode("node_2");

	// druha uroven
//	graph.addSubgraph("cluster_0");
//	graph.addSubgraph("cluster_1");
//	graph.addSubgraph("cluster_2");
//
//	// treti uroven
//	(graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_0");
//	(graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_1");
//	(graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_2");
//
//	(graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_0");
//	(graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_1");
//	(graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_2");
//
//	(graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_0");
//	(graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_1");
//	(graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_2");
//
//	// ctvrta uroven
//	// cluster 0
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_0");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_1");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_2");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_2");
//
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_0");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_1");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_2");
//
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_0");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_1");
//	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_2");
//
//	// cluster 1
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_0");
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_1");
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_2");
//
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_0");
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_1");
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_2");
//
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_0");
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_1");
//	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_2");
//
//	// cluster 2
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_0");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_1");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_2");
//
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_0");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_1");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_2");
//
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_0");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_1");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_2");
//
//	// ----------
//
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->addSubgraph("2_2_1_0");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->addSubgraph("2_2_1_0_0");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->addSubgraph("2_2_1_0_1");
//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->getSubgraph("2_2_1_0_1")->addNode("node_1");
//
////	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_2")->addNode("node_1");
//
//	node = graph.getNode("node_1");
//
//	graph.addEdge("node_1", "node_2");
//
//	graph.addNode("node_3");
//	graph.setNodeAttr("node_3", "asd", "asd");
//
//	node = graph.getNode("node_3");
//	graph.setNodeAttr(node, "bflmpsvz", 10);
//
//	graph.addEdge("node_2", "node_3");

//	Plotter plotter;
//
//	plotter.getDot();

	Plotter *plotter = new GraphvizPlotter();

	Graph *graph = plotter->graph;

	graph->setDefaultNodeAttr("string", "asd");
	graph->setDefaultNodeAttr("int", 10);
	graph->setDefaultNodeAttr("double", 10.3234);
	graph->setDefaultNodeAttr("bool", true);

	graph->setDefaultEdgeAttr("size", 10);
	graph->setDefaultEdgeAttr("color", ".7 .3 .4");

	graph->addEdge("a", "b");
	graph->addEdge("b","c");

	node = graph->getNode("a");
	node->setAttr("label", "node_node");

	subgraph = graph->addSubgraph("cluster_0");
	subgraph->addEdge("x","y");
	subgraph->addEdge("a","z");

	subgraph = subgraph->addSubgraph("cluster_0_0");
	subgraph->addEdge("petr", "mirek");
	subgraph->addEdge("mirek", "b");
	subgraph->addEdge("x", "petr");

	plotter->getDot();

	return 0;
}