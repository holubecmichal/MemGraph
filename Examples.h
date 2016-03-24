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

	static const char *dotman_27_dot() {
		return "digraph G {\n"
				"\tcompound=true;\n"
				"\tnode [color=pink];\n"
				"\n"
				"\tsubgraph cluster0 {\n"
				"\t\tnodesep=1.0;\n\n"
				"\t\tnode [fontname=Courier,shape=box];\n\n"
				"\t\tedge [color=Blue,fontname=Arial,shape=ellipse];\n\n"
				"\t\ta -> b;\n"
				"\t\tx [color=yellow];\n"
				"\t\ta [color=pink];\n"
				"\t\ta -> c [color=red, arrowhead=dot];\n"
				"\t\tb -> d;\n"
				"\t\tc -> d;\n"
				"\t}\n"
				"\n"
				"\tsubgraph cluster1 {\n"
				"\t\te [color=pink, fontname=Courier, penwidth=1.0];\n"
				"\t\te -> g;\n"
				"\t\te -> f [color=red];\n"
				"\t}\n"
				"\n"
				"\tb -> f [lhead=cluster1];\n"
				"\td -> e;\n"
				"\tc -> g [lhead=cluster1,ltail=cluster0];\n"
				"\tc -> e [ltail=cluster0];\n"
				"\td -> h;\n"
				"}";
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
//		graph->setAttr("rank", "same;ITManager Teacher1 Teacher2");

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

	static void forester_1(Graph *graph) {
// 		digraph "observer-0001-0000" {
//			label=<<FONT POINT-SIZE="18">observer-0001-0000</FONT>>;
//			clusterrank=local;
//			labelloc=t;
		graph->setHtmlAttr("label","<FONT POINT-SIZE=\"18\">observer-0001-0000</FONT>");
		graph->setAttr("clusterrank","local");
		graph->setAttr("labelloc","t");

		Attributes subgraphs_attrs;
		subgraphs_attrs.setAttr("rank","same");
		subgraphs_attrs.setAttr("color","black");
		subgraphs_attrs.setAttr("fontcolor","black");
		subgraphs_attrs.setAttr("style","dashed");
		subgraphs_attrs.setAttr("penwidth","1.0");

//			subgraph "cluster_treeaut0" {
//				rank=same;
//				label="TA 0";
//				labeljust=right;
//				color=black;
//				fontcolor=black;
//				bgcolor=green;
//				style=dashed;
//				penwidth=1.0;

		Subgraph *subgraph = graph->addSubgraph("cluster_treeaut0");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("bgcolor","green")
				->setAttr("label","TA 0")
				->setAttr("labeljust","right");

//				subgraph "cluster_treeaut0_q1_0" {
//					rank=same;
//					label=q1;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;

		subgraph = subgraph->addSubgraph("cluster_treeaut0_q1_0");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("bgcolor","orange")
				->setAttr("label","q1")
				->setAttr("labeljust","left");

//
//					"39517688" [shape=ellipse, style=filled, fillcolor=lightblue, label="__global_vars_block"];
//					"39517688.0" [shape=box, style=filled, fillcolor=pink, label="__fake_global__"];
//					"39517688" -> "39517688.0"[label="[0:1:+0]"];
//				}

		subgraph->addNode("39517688")
				->setAttr("shape","ellipse")
				->setAttr("style","filled")
				->setAttr("fillcolor","lightblue")
				->setAttr("label","__global_vars_block");

		subgraph->addNode("39517688.0")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label","__fake_global__");

		subgraph->addEdge("39517688","39517688.0")
				->setAttr("label", "[0:1:+0]");
//
//				subgraph "cluster_treeaut0_r0_1" {
//					rank=same;
//					label=r0;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//					"18446744073276704883" [shape=box, style=filled, fillcolor=red, label="(undef)"];
//				}
//
//			}

		subgraph = graph->getSubgraph("cluster_treeaut0")->addSubgraph("cluster_treeaut0_r0_1");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r0")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");
		subgraph->addNode("18446744073276704883")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","red")
				->setAttr("label","(undef)");

//			subgraph "cluster_treeaut1" {
//				rank=same;
//				label="TA 1";
//				labeljust=right;
//				color=black;
//				fontcolor=black;
//				bgcolor=green;
//				style=dashed;
//				penwidth=1.0;
//

		subgraph = graph->addSubgraph("cluster_treeaut1");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","TA 1")
				->setAttr("labeljust","right")
				->setAttr("bgcolor","green");

//				subgraph "cluster_treeaut1_q24_2" {
//					rank=same;
//					label=q24;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;

		subgraph = subgraph->addSubgraph("cluster_treeaut1_q24_2");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","q24")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

//
//					"39770200" [shape=ellipse, style=filled, fillcolor=lightblue, label="main:1976"];
//					"39770200.0" [shape=box, style=filled, fillcolor=pink, label="_pABP"];
//					"39770200" -> "39770200.0"[label="[0:4:+0]"];
//					"39770200.4" [shape=box, style=filled, fillcolor=pink, label="_retaddr"];
//					"39770200" -> "39770200.4"[label="[4:8:+0]"];

		subgraph->addNode("39770200")
				->setAttr("shape","ellipse")
				->setAttr("style","filled")
				->setAttr("fillcolor","lightblue")
				->setAttr("label","main:1976");

		subgraph->addNode("39770200.0")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label","_pABP");

		subgraph->addEdge("39770200","39770200.0")
				->setAttr("label","[0:4:+0]");

		subgraph->addNode("39770200.4")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label","_retaddr");

		subgraph->addEdge("39770200","39770200.4")
				->setAttr("label","[4:8:+0]");

//					"39770200.12" [shape=box, style=filled, fillcolor=pink, label="x"];
//					"39770200" -> "39770200.12"[label="[12:4:+0]"];
//					"39770200.16" [shape=box, style=filled, fillcolor=pink, label="y"];
//					"39770200" -> "39770200.16"[label="[16:4:+0]"];
//					"39770200.20" [shape=box, style=filled, fillcolor=pink, label="found"];
//					"39770200" -> "39770200.20"[label="[20:1:+0]"];
//				}
//

		subgraph->addNode("39770200.12")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label","x");

		subgraph->addEdge("39770200","39770200.12")
				->setAttr("label","[12:4:+0]");

		subgraph->addNode("39770200.16")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label","y");

		subgraph->addEdge("39770200","39770200.16")
				->setAttr("label","[16:4:+0]");

		subgraph->addNode("39770200.20")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label","found");

		subgraph->addEdge("39770200","39770200.20")
				->setAttr("label","[20:1:+0]");


//				subgraph "cluster_treeaut1_r0_3" {
//					rank=same;
//					label=r0;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//					"18446744073519815761" [shape=box, style=filled, fillcolor=red, label="(undef)"];
//				}

		subgraph = graph->getSubgraph("cluster_treeaut1")->addSubgraph("cluster_treeaut1_r0_3");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r0")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

		subgraph->addNode("18446744073519815761")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","red")
				->setAttr("label","(undef)");

//
//				subgraph "cluster_treeaut1_r1_4" {
//					rank=same;
//					label=r1;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//					"18446744071986306303" [shape=box, style=filled, fillcolor=red, label="(int)0"];
//				}

		subgraph = graph->getSubgraph("cluster_treeaut1")->addSubgraph("cluster_treeaut1_r1_4");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r1")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

		subgraph->addNode("18446744071986306303")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","red")
				->setAttr("label","(int)0");


//
//				subgraph "cluster_treeaut1_r2_5" {
//					rank=same;
//					label=r2;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//					"18446744072281953354" [shape=box, style=filled, fillcolor=red, label="(native_ptr)0x25f6370"];
//				}

		subgraph = graph->getSubgraph("cluster_treeaut1")->addSubgraph("cluster_treeaut1_r2_5");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r2")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

		subgraph->addNode("18446744072281953354")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","red")
				->setAttr("label","(native_ptr)0x25f6370");

//
//				subgraph "cluster_treeaut1_r3_6" {
//					rank=same;
//					label=r3;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//				}

		subgraph = graph->getSubgraph("cluster_treeaut1")->addSubgraph("cluster_treeaut1_r3_6");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r3")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

//
//			}

//		    subgraph "cluster_treeaut2" {
//				rank=same;
//				label="TA 2";
//				labeljust=right;
//				color=black;
//				fontcolor=black;
//				bgcolor=green;
//				style=dashed;
//				penwidth=1.0;

		subgraph = graph->addSubgraph("cluster_treeaut2");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","TA 2")
				->setAttr("labeljust","right")
				->setAttr("bgcolor","green");

//
//				subgraph "cluster_treeaut2_q25_7" {
//					rank=same;
//					label=q25;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;

		subgraph = subgraph->addSubgraph("cluster_treeaut2_q25_7");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","q25")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

//
//					"39502392" [shape=ellipse, style=filled, fillcolor=lightblue, label="SLL"];
//					"39502392.0" [shape=box, style=filled, fillcolor=pink, label=".next"];
//					"39502392" -> "39502392"[label="[0:4:+0]"];
//					"39502392.4" [shape=box, style=filled, fillcolor=pink, label=".data"];
//					"39502392" -> "39502392.4"[label="[4:4:+0]"];

		subgraph->addNode("39502392")
				->setAttr("shape","ellipse")
				->setAttr("style","filled")
				->setAttr("fillcolor","lightblue")
				->setAttr("label","SLL");

		subgraph->addNode("39502392.0")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label",".next");

		subgraph->addNode("39502392.4")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label",".data");

		subgraph->addEdge("39502392","39502392.0")
				->setAttr("label","[0:4:+0]");

		subgraph->addEdge("39502392","39502392.4")
				->setAttr("label","[4:4:+0]");


//				}
//
//				subgraph "cluster_treeaut2_q25_8" {
//					rank=same;
//					label=q25;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;

		subgraph = graph->getSubgraph("cluster_treeaut2")->addSubgraph("cluster_treeaut2_q25_8");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","q25")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

//
//					"39382008" [shape=ellipse, style=filled, fillcolor=lightblue, label="SLL"];
//					"39382008.0" [shape=box, style=filled, fillcolor=pink, label=".next"];
//					"39382008" -> "39382008.0"[label="[0:4:+0]"];
//					"39382008.4" [shape=box, style=filled, fillcolor=pink, label=".data"];
//					"39382008" -> "39382008.4"[label="[4:4:+0]"];

		subgraph->addNode("39382008")
				->setAttr("shape","ellipse")
				->setAttr("style","filled")
				->setAttr("fillcolor","lightblue")
				->setAttr("label","SLL");

		subgraph->addNode("39382008.0")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label",".next");

		subgraph->addNode("39382008.4")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","pink")
				->setAttr("label",".data");

		subgraph->addEdge("39382008","39382008.0")
				->setAttr("label","[0:4:+0]");

		subgraph->addEdge("39382008","39382008.4")
				->setAttr("label","[4:4:+0]");

//				}
//
//				subgraph "cluster_treeaut2_r1_9" {
//					rank=same;
//					label=r1;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//					"18446744072158584617" [shape=box, style=filled, fillcolor=red, label="(int)0"];
//				}

		subgraph = graph->getSubgraph("cluster_treeaut2")->addSubgraph("cluster_treeaut2_r1_9");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r1")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

		subgraph->addNode("18446744072158584617")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","red")
				->setAttr("label","(int)0");

//
//				subgraph "cluster_treeaut2_r4_10" {
//					rank=same;
//					label=r4;
//					labeljust=left;
//					color=black;
//					fontcolor=black;
//					bgcolor=orange;
//					style=dashed;
//					penwidth=1.0;
//
//					"18446744072751709389" [shape=box, style=filled, fillcolor=red, label="(int)1"];
//				}
//
//			}

		subgraph = graph->getSubgraph("cluster_treeaut2")->addSubgraph("cluster_treeaut2_r4_10");
		subgraph->setAttrs(&subgraphs_attrs);
		subgraph->setAttr("label","r4")
				->setAttr("labeljust","left")
				->setAttr("bgcolor","orange");

		subgraph->addNode("18446744072751709389")
				->setAttr("shape","box")
				->setAttr("style","filled")
				->setAttr("fillcolor","red")
				->setAttr("label","(int)1");

//			"39517688.0" -> "18446744073276704883";
//			"39770200.0" -> "18446744071986306303";
//			"39770200.4" -> "18446744072281953354";
//			"39770200.12" -> "39502392";
//			"39770200.12" -> "39382008";
//			"39770200.16" -> "18446744073519815761";
//			"39770200.20" -> "18446744073519815761";
//			"39502392.0" -> "39502392";
//			"39502392.0" -> "39382008";
//			"39502392.4" -> "18446744072158584617";
//			"39382008.0" -> "18446744072158584617";
//			"39382008.4" -> "18446744072751709389";
//		}

		graph->addEdge("39517688.0","18446744073276704883");
		graph->addEdge("39770200.0","18446744071986306303");
		graph->addEdge("39770200.4","18446744072281953354");
		graph->addEdge("39770200.12","39502392");
		graph->addEdge("39770200.12","39382008");
		graph->addEdge("39770200.16","18446744073519815761");
		graph->addEdge("39770200.20","18446744073519815761");
		graph->addEdge("39502392.0","39502392");
		graph->addEdge("39502392.0","39382008");
		graph->addEdge("39502392.4","18446744072158584617");
		graph->addEdge("39382008.0","18446744072158584617");
		graph->addEdge("39382008.4","18446744072751709389");

	}

	static const char *predator_dot_file() {
		return "digraph \"snapshot-01-0011\" {\n"
				"\tlabel=<<FONT POINT-SIZE=\"18\">snapshot-01-0011</FONT>>;\n"
				"\tclusterrank=local;\n"
				"\tlabelloc=t;\n"
				"\t\"6\" [shape=box, color=blue, fontcolor=blue, label=\"CL#1991:list [obj = #6] field#7\"];\n"
				"subgraph \"cluster1\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"9\" [shape=box, color=black, fontcolor=black, label=\"#9 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"10\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #10 [size = 4B]\"];\n"
				"\t\"9\" -> \"10\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"11\" [shape=box, color=black, fontcolor=black, label=\".next #11\"];\n"
				"\t\"9\" -> \"11\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster2\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"13\" [shape=box, color=black, fontcolor=black, label=\"#13 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"14\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #14 [size = 4B]\"];\n"
				"\t\"13\" -> \"14\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"15\" [shape=box, color=black, fontcolor=black, label=\".next #15\"];\n"
				"\t\"13\" -> \"15\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster3\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"17\" [shape=box, color=black, fontcolor=black, label=\"#17 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"18\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #18 [size = 4B]\"];\n"
				"\t\"17\" -> \"18\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"19\" [shape=box, color=black, fontcolor=black, label=\".next #19\"];\n"
				"\t\"17\" -> \"19\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster4\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"21\" [shape=box, color=black, fontcolor=black, label=\"#21 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"22\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #22 [size = 4B]\"];\n"
				"\t\"21\" -> \"22\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"23\" [shape=box, color=black, fontcolor=black, label=\".next #23\"];\n"
				"\t\"21\" -> \"23\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster5\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"25\" [shape=box, color=black, fontcolor=black, label=\"#25 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"26\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #26 [size = 4B]\"];\n"
				"\t\"25\" -> \"26\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"27\" [shape=box, color=black, fontcolor=black, label=\".next #27\"];\n"
				"\t\"25\" -> \"27\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster6\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"29\" [shape=box, color=black, fontcolor=black, label=\"#29 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"30\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #30 [size = 4B]\"];\n"
				"\t\"29\" -> \"30\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"31\" [shape=box, color=black, fontcolor=black, label=\".next #31\"];\n"
				"\t\"29\" -> \"31\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster7\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"33\" [shape=box, color=black, fontcolor=black, label=\"#33 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"34\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #34 [size = 4B]\"];\n"
				"\t\"33\" -> \"34\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"35\" [shape=box, color=black, fontcolor=black, label=\".next #35\"];\n"
				"\t\"33\" -> \"35\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster8\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"37\" [shape=box, color=black, fontcolor=black, label=\"#37 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"38\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #38 [size = 4B]\"];\n"
				"\t\"37\" -> \"38\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"39\" [shape=box, color=black, fontcolor=black, label=\".next #39\"];\n"
				"\t\"37\" -> \"39\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster9\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"41\" [shape=box, color=black, fontcolor=black, label=\"#41 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"42\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #42 [size = 4B]\"];\n"
				"\t\"41\" -> \"42\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"43\" [shape=box, color=black, fontcolor=black, label=\".next #43\"];\n"
				"\t\"41\" -> \"43\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster10\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"45\" [shape=box, color=black, fontcolor=black, label=\"#45 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"46\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #46 [size = 4B]\"];\n"
				"\t\"45\" -> \"46\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"47\" [shape=box, color=black, fontcolor=black, label=\".next #47\"];\n"
				"\t\"45\" -> \"47\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster11\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"49\" [shape=box, color=black, fontcolor=black, label=\"#49 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"50\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #50 [size = 4B]\"];\n"
				"\t\"49\" -> \"50\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"51\" [shape=box, color=black, fontcolor=black, label=\".next #51\"];\n"
				"\t\"49\" -> \"51\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster12\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"66\" [shape=box, color=black, fontcolor=black, label=\"#66 [SC_ON_HEAP, size = 12 B]\"];\n"
				"\t\"82\" [shape=box, color=gray, fontcolor=gray, style=dotted, label=\".nth #82 [size = 4B]\"];\n"
				"\t\"66\" -> \"82\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"87\" [shape=box, color=black, fontcolor=black, label=\".next #87\"];\n"
				"\t\"66\" -> \"87\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"\t\"88\" [shape=box, color=blue, fontcolor=blue, style=dotted, label=\"CL#1992:i [obj = #88] field#89 [size = 4B]\"];\n"
				"\t\"12\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#12 [off = 0, obj = #9]\"];\n"
				"\t\"12\" -> \"9\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"16\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#16 [off = 0, obj = #13]\"];\n"
				"\t\"16\" -> \"13\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"20\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#20 [off = 0, obj = #17]\"];\n"
				"\t\"20\" -> \"17\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"24\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#24 [off = 0, obj = #21]\"];\n"
				"\t\"24\" -> \"21\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"28\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#28 [off = 0, obj = #25]\"];\n"
				"\t\"28\" -> \"25\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"32\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#32 [off = 0, obj = #29]\"];\n"
				"\t\"32\" -> \"29\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"36\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#36 [off = 0, obj = #33]\"];\n"
				"\t\"36\" -> \"33\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"40\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#40 [off = 0, obj = #37]\"];\n"
				"\t\"40\" -> \"37\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"44\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#44 [off = 0, obj = #41]\"];\n"
				"\t\"44\" -> \"41\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"48\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#48 [off = 0, obj = #45]\"];\n"
				"\t\"48\" -> \"45\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"52\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#52 [off = 0, obj = #49]\"];\n"
				"\t\"52\" -> \"49\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"67\" [shape=ellipse, penwidth=2, fontcolor=black, label=\"#67 [off = 0, obj = #66]\"];\n"
				"\t\"67\" -> \"66\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"6\" -> \"67\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely13\" [shape=plaintext, fontcolor=red, label=\"[int] 10 (#61)\"];\n"
				"\t\"10\" -> \"lonely13\" [color=blue, fontcolor=blue];\n"
				"\t\"11\" -> \"16\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely14\" [shape=plaintext, fontcolor=red, label=\"[int] 9 (#60)\"];\n"
				"\t\"14\" -> \"lonely14\" [color=blue, fontcolor=blue];\n"
				"\t\"15\" -> \"20\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely15\" [shape=plaintext, fontcolor=red, label=\"[int] 8 (#59)\"];\n"
				"\t\"18\" -> \"lonely15\" [color=blue, fontcolor=blue];\n"
				"\t\"19\" -> \"24\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely16\" [shape=plaintext, fontcolor=red, label=\"[int] 7 (#58)\"];\n"
				"\t\"22\" -> \"lonely16\" [color=blue, fontcolor=blue];\n"
				"\t\"23\" -> \"28\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely17\" [shape=plaintext, fontcolor=red, label=\"[int] 6 (#57)\"];\n"
				"\t\"26\" -> \"lonely17\" [color=blue, fontcolor=blue];\n"
				"\t\"27\" -> \"32\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely18\" [shape=plaintext, fontcolor=red, label=\"[int] 5 (#56)\"];\n"
				"\t\"30\" -> \"lonely18\" [color=blue, fontcolor=blue];\n"
				"\t\"31\" -> \"36\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely19\" [shape=plaintext, fontcolor=red, label=\"[int] 4 (#55)\"];\n"
				"\t\"34\" -> \"lonely19\" [color=blue, fontcolor=blue];\n"
				"\t\"35\" -> \"40\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely20\" [shape=plaintext, fontcolor=red, label=\"[int] 3 (#54)\"];\n"
				"\t\"38\" -> \"lonely20\" [color=blue, fontcolor=blue];\n"
				"\t\"39\" -> \"44\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely21\" [shape=plaintext, fontcolor=red, label=\"[int] 2 (#53)\"];\n"
				"\t\"42\" -> \"lonely21\" [color=blue, fontcolor=blue];\n"
				"\t\"43\" -> \"48\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely22\" [shape=plaintext, fontcolor=red, label=\"[int] 1 (#1)\"];\n"
				"\t\"46\" -> \"lonely22\" [color=blue, fontcolor=blue];\n"
				"\t\"47\" -> \"52\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely23\" [shape=plaintext, fontcolor=blue, label=\"[int] 0\"];\n"
				"\t\"50\" -> \"lonely23\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely24\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
				"\t\"51\" -> \"lonely24\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely25\" [shape=plaintext, fontcolor=red, label=\"[int] 11 (#81)\"];\n"
				"\t\"82\" -> \"lonely25\" [color=blue, fontcolor=blue];\n"
				"\t\"87\" -> \"12\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely26\" [shape=plaintext, fontcolor=red, label=\"[int] 12 (#62)\"];\n"
				"\t\"88\" -> \"lonely26\" [color=blue, fontcolor=blue];\n"
				"}";
	}
};


#endif //BACHELOR_EXAMPLES_H
