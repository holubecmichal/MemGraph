#include <iostream>
#include "attribute.h"
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"

using namespace std;

// todo construct, destruct

int main() {
	Graph graph;
	Attributes *attrs;
	Edge *edge;
	Subgraph *subgraph;
	Node *node;
	GraphComponent *graphComponent;

//	subgraph->addNode("asd_1");
//	subgraph->addNode("asd_2");
//	subgraph->addNode("node_2");

	// druha uroven
	graph.addSubgraph("cluster_0");
	graph.addSubgraph("cluster_1");
	graph.addSubgraph("cluster_2");

	// treti uroven
	(graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_0");
	(graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_1");
	(graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_2");

	(graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_0");
	(graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_1");
	(graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_2");

	(graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_0");
	(graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_1");
	(graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_2");

	// ctvrta uroven
	// cluster 0
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_0");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_1");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_2");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_2");

	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_0");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_1");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_2");

	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_0");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_1");
	(graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_2");

	// cluster 1
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_0");
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_1");
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_2");

	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_0");
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_1");
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_2");

	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_0");
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_1");
	(graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_2");

	// cluster 2
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_0");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_1");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_2");

	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_0");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_1");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_2");

	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_0");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_1");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_2");

	// ----------

	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->addSubgraph("2_2_1_0");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->addSubgraph("2_2_1_0_0");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->addSubgraph("2_2_1_0_1");
	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->getSubgraph("2_2_1_0_1")->addNode("node_1");

//	(graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_2")->addNode("node_1");

	node = graph.getNode("node_1");

	graph.addEdge("node_1", "node_2");

	graph.addNode("node_3");
	graph.setNodeAttr("node_3", "asd", "asd");

	node = graph.getNode("node_3");
	graph.setNodeAttr(node, "bflmpsvz", 10);

	return 0;
}