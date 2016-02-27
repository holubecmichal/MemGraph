#include <iostream>
#include "attribute.h"
#include "attributes.h"
#include "node.h"
#include "edge.h"
#include "graph.h"

using namespace std;

// todo construct, destruct
// todo refactoring

int main() {
	graph Graph;
	attributes *attrs;
	edge *Edge;
	subgraph *Subgraph;
	node *Node;
	graphComponent *GraphComponent;

//	Subgraph->addNode("asd_1");
//	Subgraph->addNode("asd_2");
//	Subgraph->addNode("node_2");

	// druha uroven
	Graph.addSubgraph("cluster_0");
	Graph.addSubgraph("cluster_1");
	Graph.addSubgraph("cluster_2");

	// treti uroven
	(Graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_0");
	(Graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_1");
	(Graph.getSubgraph("cluster_0"))->addSubgraph("cluster_0_2");

	(Graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_0");
	(Graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_1");
	(Graph.getSubgraph("cluster_1"))->addSubgraph("cluster_1_2");

	(Graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_0");
	(Graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_1");
	(Graph.getSubgraph("cluster_2"))->addSubgraph("cluster_2_2");

	// ctvrta uroven
	// cluster 0
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_0");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_1");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_2");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->addSubgraph("cluster_0_0_2");

	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_0");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_1");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_1")->addSubgraph("cluster_0_1_2");

	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_0");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_1");
	(Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_2")->addSubgraph("cluster_0_2_2");

	// cluster 1
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_0");
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_1");
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_0")->addSubgraph("cluster_1_0_2");

	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_0");
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_1");
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_1")->addSubgraph("cluster_1_1_2");

	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_0");
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_1");
	(Graph.getSubgraph("cluster_1"))->getSubgraph("cluster_1_2")->addSubgraph("cluster_1_2_2");

	// cluster 2
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_0");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_1");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_0")->addSubgraph("cluster_2_0_2");

	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_0");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_1");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_1")->addSubgraph("cluster_2_1_2");

	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_0");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_1");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->addSubgraph("cluster_2_2_2");

	// ----------

	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->addSubgraph("2_2_1_0");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->addSubgraph("2_2_1_0_0");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->addSubgraph("2_2_1_0_1");
	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_1")->getSubgraph("2_2_1_0")->getSubgraph("2_2_1_0_1")->addNode("node_1");

//	(Graph.getSubgraph("cluster_2"))->getSubgraph("cluster_2_2")->getSubgraph("cluster_2_2_2")->addNode("node_1");

	//Node = (Graph.getSubgraph("cluster_0"))->getSubgraph("cluster_0_0")->getSubgraph("cluster_0_0_2")->getNodeInGraph("node_1");

	Graph.addEdge("node_1", "node_2");

	return 0;
}