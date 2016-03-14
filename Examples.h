//
// Created by Michael Holubec on 10.03.16.
//

#ifndef BACHELOR_EXAMPLES_H
#define BACHELOR_EXAMPLES_H


#include "graph.h"

class Examples {
public:
	static void dotman_23(Graph *graph) {
		Subgraph *subgraph;

		//	subgraph cluster0 {
		subgraph = graph->addSubgraph("cluster0");
		//  	node [style=filled,color=white];
		subgraph->setNodeAttr("style", "filled");
		subgraph->setNodeAttr("color", "white");
		//  	style=filled;
		//	    color=lightgrey;
		subgraph->setAttr("style", "filled");
		subgraph->setAttr("color", "lightgrey");
		//		a0 -> a1 -> a2 -> a3;
		subgraph->addEdge("a0", "a1");
		subgraph->addEdge("a1", "a2");
		subgraph->addEdge("a2", "a3");
		//		label = "process #1";
		subgraph->setAttr("label", "process #1");
		//	}

		//	subgraph cluster1 {
		subgraph = graph->addSubgraph("cluster1");
		//	    node [style=filled];
		subgraph->setNodeAttr("style", "filled");
		//	    b0 -> b1 -> b2 -> b3;
		subgraph->addEdge("b0", "b1");
		subgraph->addEdge("b1", "b2");
		subgraph->addEdge("b2", "b3");
		//	    label = "process #2";
		//	    color=blue
		subgraph->setAttr("label", "process #2");
		subgraph->setAttr("color", "blue");
		//	}

		//	start -> a0;
		graph->addEdge("start", "a0");
		//	start -> b0;
		graph->addEdge("start", "b0");
		//	a1 -> b3;
		graph->addEdge("a1", "b3");
		//	b2 -> a3;
		graph->addEdge("b2", "a3");
		//	a3 -> a0;
		graph->addEdge("a3", "a0");
		//	a3 -> end;
		graph->addEdge("a3", "end");
		//	b3 -> end;
		graph->addEdge("b3", "end");
		//	start [shape=Mdiamond];
		graph->getNode("start")->setAttr("shape","Mdiamond");
		//	end [shape=Msquare];
		graph->getNode("end")->setAttr("shape","Msquare");
	}

	static void dotman_27(Graph *graph) {
		Subgraph *subgraph;
		Edge *edge;

		graph->setAttr("compound", true);
		subgraph = graph->addSubgraph("cluster0");
		subgraph->addEdge("a","b");
		subgraph->addEdge("a","c");
		subgraph->addEdge("b","d");
		subgraph->addEdge("c","d");

		subgraph = graph->addSubgraph("cluster1");
		subgraph->addEdge("e","g");
		subgraph->addEdge("e","f");

		graph->addEdge("b","f")
				->setAttr("lhead","cluster1");
		graph->addEdge("d", "e");
		graph->addEdge("c","g")
				->setAttr("ltail","cluster0")
				->setAttr("lhead","cluster1");
		graph->addEdge("c","e")
				->setAttr("ltail","cluster0");
		graph->addEdge("d","h");
	}

	static void tonyballantyne_com_51(Graph *graph) {
//		digraph hierarchy {
//			nodesep=1.0 // increases the separation between nodes
//
//			node [color=Red,fontname=Courier,shape=box] //All nodes will this shape and colour
//			edge [color=Blue, style=dashed] //All the lines look like this
//
//			Headteacher->{Deputy1 Deputy2 BusinessManager}
//			Deputy1->{Teacher1 Teacher2}
//			BusinessManager->ITManager
//			{rank=same;ITManager Teacher1 Teacher2}  // Put them on the same level
//		}

		graph->setAttr("nodesep",1);

		Attributes node_attrs;
		Attributes edge_attrs;

		node_attrs.setAttr("color","red");
		node_attrs.setAttr("fontname","Courier");
		node_attrs.setAttr("shape","box");

		edge_attrs.setAttr("color","blue");
		edge_attrs.setAttr("style","dashed");

		graph->setNodeAttrs(&node_attrs);
		graph->setEdgeAttrs(&edge_attrs);

		graph->addEdge("Headteacher", "Deputy1");
		graph->addEdge("Headteacher", "Deputy2");
		graph->addEdge("Headteacher", "BusinessManager");
		graph->addEdge("Deputy1", "Teacher1");
		graph->addEdge("Deputy1", "Teacher2");
		graph->addEdge("BusinessManager", "ITManager");

		// todo pridat zasobnik contextu (attr rank)
		graph->setAttr("rank", "same;ITManager Teacher1 Teacher2");

	}

	static void predator_1(Graph *graph) {
//		digraph G {
//				label=<<FONT POINT-SIZE="18">test-0001-snapshot-0001</FONT>>;
//				clusterrank=local;
//				labelloc=t;
//
//				20 [label="CL#2335:ptr [obj = #20] field#22",color=blue,shape=box,fontcolor=blue];
//				15 [label="#15 [off = 0, obj = #14]",fontcolot=black,penwidth=2,shape=ellipse];
//				24 [label="#24 [off = 0, obj = #23]",fontcolot=black,penwidth=2,shape=ellipse];
//				lonely3 [label="NULL",shape=plaintext,fontcolor=blue];
//
//				subgraph cluster1 {
//					label="";
//					rank=same;
//					color=black;
//					fontcolot=black;
//					bgcolor=white;
//					penwidth=1;
//					style=dashed;
//
//					14 [label="#14 [SC_ON_HEAP, size = 8 B]",color=black,shape=box,fontcolor=black];
//					16 [label=".next #16",color=black,shape=box,fontcolor=black];
//
//					14 -> 16 [label="[+0]",color=black,fontcolor=black];
//				}
//
//				subgraph cluster2 {
//					label="";
//					rank=same;
//					color=black;
//					fontcolot=black;
//					bgcolor=white;
//					penwidth=1;
//					style=dashed;
//
//					23 [label="#23 [SC_ON_HEAP, size = 8 B]",color=black,shape=box,fontcolor=black];
//					25 [label=".next #25",color=black,shape=box,fontcolor=black];
//
//					23 -> 25 [label="[+0]",color=black,fontcolor=black];
//				}
//
//				16 -> lonely3 [color=blue,fontcolor=black];
//				20 -> 24 [color=blue,fontcolor=black];
//				25 -> 15 [color=blue,fontcolor=black];
//				24 -> 23 [label="[+0]",color=blue,fontcolor=black];
//				15 -> 14 [label="[+0]",color=blue,fontcolor=black];
//		}

		Subgraph *subgraph;
		Attributes subgraph_attrs;

		subgraph_attrs.setAttr("rank","same");
		subgraph_attrs.setAttr("label","");
		subgraph_attrs.setAttr("color","black");
		subgraph_attrs.setAttr("fontcolor","black");
		subgraph_attrs.setAttr("bgcolor","white");
		subgraph_attrs.setAttr("penwidth",1.0);
		subgraph_attrs.setAttr("style","dashed");

		graph->setHtmlAttr("label","<FONT POINT-SIZE=\"18\">test-0001-snapshot-0001</FONT>");
		graph->setAttr("clusterrank","local")
				->setAttr("labelloc","t");

		subgraph = graph->addSubgraph("cluster1");
		subgraph->setAttrs(&subgraph_attrs);
		subgraph->addNode("14")
				->setAttr("shape","box")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","#14 [SC_ON_HEAP, size = 8 B]");
		subgraph->addNode("16")
				->setAttr("shape","box")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","#.next #16");
		subgraph->addEdge("14","16")
				->setAttr("color","black")
				->setAttr("fontcolor","blue")
				->setAttr("label","[+0]");

		graph->addNode("20")
				->setAttr("shape","box")
				->setAttr("color","blue")
				->setAttr("fontcolor","blue")
				->setAttr("label","CL#2335:ptr [obj = #20] field#22");

		subgraph = graph->addSubgraph("cluster2");
		subgraph->setAttrs(&subgraph_attrs);
		subgraph->addNode("23")
				->setAttr("shape","box")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","#23 [SC_ON_HEAP, size = 8 B]");
		subgraph->addNode("25")
				->setAttr("shape","box")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","#.next #25");
		subgraph->addEdge("23","25")
				->setAttr("color","black")
				->setAttr("fontcolor","blue")
				->setAttr("label","[+0]");

		graph->addNode("15")
				->setAttr("shape","ellipse")
				->setAttr("penwidth",2)
				->setAttr("fontcolor","black")
				->setAttr("label","#15 [off = 0, obj = #14]");
		graph->addNode("24")
				->setAttr("shape","ellipse")
				->setAttr("penwidth",2)
				->setAttr("fontcolor","black")
				->setAttr("label","#24 [off = 0, obj = #23]");
		graph->addNode("lonely3")
				->setAttr("shape","plaintext")
				->setAttr("fontcolor","blue")
				->setAttr("label","NULL");

		graph->addEdge("16","lonely3")
				->setAttr("color","blue")
				->setAttr("fontcolor","blue");
		graph->addEdge("20","24")
				->setAttr("color","blue")
				->setAttr("fontcolor","blue");
		graph->addEdge("25","15")
				->setAttr("color","blue")
				->setAttr("fontcolor","blue");

		graph->addEdge("24","23")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","[+0]");
		graph->addEdge("15","14")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","[+0]");
	}
};


#endif //BACHELOR_EXAMPLES_H
