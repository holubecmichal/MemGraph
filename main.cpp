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

	Plotter *plotter = new GraphvizPlotter();

	Graph *graph = plotter->graph;
	graph->setType(digraph);

	// todo setDefaultGraphAttr
	// todo implementace graphvizu

	graph->setHtmlAttr("label", "<FONT POINT-SIZE=\"18\">test-0001-snapshot-0001</FONT>");
	graph->setAttr("clusterrank", "local");
	graph->setAttr("labelloc", "t");

	subgraph = graph->addSubgraph("cluster1")->setAttr("label", "")->setAttr("rank", "same")->setAttr("color","black")->setAttr("fontcolot","black")->setAttr("bgcolor","white")->setAttr("penwidth",1.0)->setAttr("style","dashed");
	subgraph->addNode("14")->setAttr("shape","box")->setAttr("color","black")->setAttr("fontcolor","black")->setAttr("label", "#14 [SC_ON_HEAP, size = 8 B]");
	subgraph->addNode("16")->setAttr("shape","box")->setAttr("color","black")->setAttr("fontcolor","black")->setAttr("label", ".next #16");
	subgraph->addEdge("14", "16")->setAttr("color", "black")->setAttr("fontcolor", "black")->setAttr("label","[+0]");

	graph->addNode("20")->setAttr("shape", "box")->setAttr("color", "blue")->setAttr("fontcolor", "blue")->setAttr("label","CL#2335:ptr [obj = #20] field#22");

	subgraph = graph->addSubgraph("cluster2")->setAttr("label", "")->setAttr("rank", "same")->setAttr("color","black")->setAttr("fontcolot","black")->setAttr("bgcolor","white")->setAttr("penwidth",1.0)->setAttr("style","dashed");
	subgraph->addNode("23")->setAttr("shape","box")->setAttr("color","black")->setAttr("fontcolor","black")->setAttr("label", "#23 [SC_ON_HEAP, size = 8 B]");
	subgraph->addNode("25")->setAttr("shape","box")->setAttr("color","black")->setAttr("fontcolor","black")->setAttr("label", ".next #25");
	subgraph->addEdge("23", "25")->setAttr("color", "black")->setAttr("fontcolor", "black")->setAttr("label","[+0]");

	graph->setDefaultNodeAttr("shape","ellipse");
	graph->setDefaultNodeAttr("penwidth","2");
	graph->setDefaultNodeAttr("fontcolot","black");
	graph->addNode("15")->setAttr("label","#15 [off = 0, obj = #14]");
	graph->addNode("24")->setAttr("label","#24 [off = 0, obj = #23]");

	graph->clearDefaultNodeAttrs();

	graph->addNode("lonely3")->setAttr("shape","plaintext")->setAttr("fontcolor","blue")->setAttr("label","NULL");

	graph->setDefaultEdgeAttr("color","blue");
	graph->setDefaultEdgeAttr("fontcolor","blue");

	graph->addEdge("16", "lonely3");
	graph->addEdge("20", "24");
	graph->addEdge("25", "15");

	graph->setDefaultEdgeAttr("fontcolor", "black");
	graph->setDefaultEdgeAttr("label", "[+0]");

	graph->addEdge("24", "23");
	graph->addEdge("15", "14");


//	digraph "test-0001-snapshot-0001" {
//		label=<<FONT POINT-SIZE="18">test-0001-snapshot-0001</FONT>>;
//		clusterrank=local;
//		labelloc=t;
//		subgraph "cluster1" {
//			rank=same;
//			label="";
//			color=black;
//			fontcolor=black;
//			bgcolor=white;
//			penwidth=1.0;
//			style=dashed;
//			"14" [shape=box, color=black, fontcolor=black, label="#14 [SC_ON_HEAP, size = 8 B]"];
//			"16" [shape=box, color=black, fontcolor=black, label=".next #16"];
//			"14" -> "16" [color=black, fontcolor=black, label="[+0]"];
//		}
//		"20" [shape=box, color=blue, fontcolor=blue, label="CL#2335:ptr [obj = #20] field#22"];
//		subgraph "cluster2" {
//			rank=same;
//			label="";
//			color=black;
//			fontcolor=black;
//			bgcolor=white;
//			penwidth=1.0;
//			style=dashed;
//			"23" [shape=box, color=black, fontcolor=black, label="#23 [SC_ON_HEAP, size = 8 B]"];
//			"25" [shape=box, color=black, fontcolor=black, label=".next #25"];
//			"23" -> "25" [color=black, fontcolor=black, label="[+0]"];
//		}
//		"15" [shape=ellipse, penwidth=2, fontcolor=black, label="#15 [off = 0, obj = #14]"];
//		"24" [shape=ellipse, penwidth=2, fontcolor=black, label="#24 [off = 0, obj = #23]"];
//		"lonely3" [shape=plaintext, fontcolor=blue, label="NULL"];
//		"16" -> "lonely3" [color=blue, fontcolor=blue];
//		"20" -> "24" [color=blue, fontcolor=blue];
//		"25" -> "15" [color=blue, fontcolor=blue];
//		"24" -> "23" [color=black, fontcolor=black, label="[+0]"];
//		"15" -> "14" [color=black, fontcolor=black, label="[+0]"];
//	}

	cout << plotter->getDot() << endl;

	return 0;
}