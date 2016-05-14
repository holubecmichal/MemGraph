//
// Created by Michael Holubec on 10.03.16.
//

#ifndef MEMGRAPH_EXAMPLES_H
#define MEMGRAPH_EXAMPLES_H


#include "graph.h"
using namespace memgraph;

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
				"\t\tsubgraph cluster01 {\n"
				"\t\t\t\tasd -> zxc [color=red];\n"
				"\t\t\t\tasd [color=yellow];\n"
				"\t\t\t\tqwe -> rty;\n"
				"\t\t}\n"
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

		graph->addEdge("vutbr", "fit");
		graph->addEdge("vutbr", "fce");
		graph->addEdge("vutbr", "feec");
		graph->addEdge("fit", "merlin");
		graph->addEdge("fit", "kazi");
		graph->addEdge("feec", "kos");
	}

	static void predator_1(Graph *graph) {
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

	static void predator_2(Graph *graph) {
		/*
		 *
digraph G {
	clusterrank=local;
	label=<<FONT POINT-SIZE="18">01-PL_ArenaAllocate-0001</FONT>>;
	labelloc=t;

	242 [color=blue,fontcolor=blue,label="CL#3121:ptr [obj = #242] field#244",shape=box];
	243 [fontcolor=blue,label="#243 VT_OBJECT [off = 0, obj = #242]",penwidth=1,shape=ellipse];
	lonely1 [fontcolor=blue,label="NULL",shape=plaintext];

	243 -> 242 [color=black,fontcolor=black,label="[+0]"];
	242 -> lonely1 [color=blue,fontcolor=blue];
}
		 */

		graph->setAttr("clusterrank","local");
		graph->setAttr("labelloc","t");
		graph->setHtmlAttr("label","<FONT POINT-SIZE=\"18\">01-PL_ArenaAllocate-0001</FONT>");

		graph->addNode("242")
				->setAttr("color","blue")
				->setAttr("fontcolor","blue")
				->setAttr("label","CL#3121:ptr [obj = #242] field#244")
				->setAttr("shape","box");

		graph->addNode("243")
				->setAttr("fontcolor","blue")
				->setAttr("label","#243 VT_OBJECT [off = 0, obj = #242]")
				->setAttr("shape","ellipse")
				->setAttr("penwidth",1);

		graph->addNode("lonely1")
				->setAttr("fontcolor","blue")
				->setAttr("label","NULL")
				->setAttr("shape","plaintext");

		graph->addEdge("243","242")
				->setAttr("color","black")
				->setAttr("fontcolor","black")
				->setAttr("label","[+0]");

		graph->addEdge("242","lonely1")
				->setAttr("color","blue")
				->setAttr("fontcolor","blue");
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
				"\tfontsize=20;\n"
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

	static const char *predator_sls_dls() {
		return "digraph \"b02-0001\" {\n"
				"\tlabel=<<FONT POINT-SIZE=\"18\">b02-0001</FONT>>;\n"
				"\tclusterrank=local;\n"
				"\tlabelloc=t;\n"
				"\t\"4\" [shape=box, color=blue, fontcolor=blue, label=\"CL#2000:dll [obj = #4] field#5\"];\n"
				"\t\"6\" [shape=box, color=blue, fontcolor=blue, label=\"CL#2016:dll [obj = #6] field#7\"];\n"
				"subgraph \"cluster1\" {\n"
				"\trank=same;\n"
				"\tlabel=\"SLS 1+, head [+0], next [+0]\";\n"
				"\tcolor=red;\n"
				"\tfontcolor=red;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=3.0;\n"
				"\tstyle=dashed;\n"
				"\t\"8\" [shape=box, color=red, fontcolor=red, label=\"#8 [SC_ON_HEAP, size = 8 B]\"];\n"
				"\t\"9\" [shape=box, color=red, fontcolor=red, penwidth=3.0, style=dashed, label=\".next #9\"];\n"
				"\t\"8\" -> \"9\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"10\" [shape=box, color=black, fontcolor=black, label=\".prev #10\"];\n"
				"\t\"8\" -> \"10\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster2\" {\n"
				"\trank=same;\n"
				"\tlabel=\"DLS 1+, head [+0], next [+0], prev [+4]\";\n"
				"\tcolor=orange;\n"
				"\tfontcolor=orange;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=3.0;\n"
				"\tstyle=dashed;\n"
				"\t\"39\" [shape=box, color=orange, fontcolor=orange, label=\"#39 [SC_ON_HEAP, size = 8 B]\"];\n"
				"\t\"40\" [shape=box, color=red, fontcolor=red, penwidth=3.0, style=dashed, label=\".next #40\"];\n"
				"\t\"39\" -> \"40\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"41\" [shape=box, color=orange, fontcolor=orange, penwidth=3.0, style=dashed, label=\".prev #41\"];\n"
				"\t\"39\" -> \"41\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"subgraph \"cluster3\" {\n"
				"\trank=same;\n"
				"\tlabel=\"\";\n"
				"\tcolor=black;\n"
				"\tfontcolor=black;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=1.0;\n"
				"\tstyle=dashed;\n"
				"\t\"45\" [shape=box, color=black, fontcolor=black, label=\"#45 [SC_ON_HEAP, size = 8 B]\"];\n"
				"\t\"46\" [shape=box, color=black, fontcolor=black, label=\".next #46\"];\n"
				"\t\"45\" -> \"46\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"47\" [shape=box, color=black, fontcolor=black, label=\".prev #47\"];\n"
				"\t\"45\" -> \"47\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
				"}\n"
				"\t\"53\" [shape=box, color=blue, fontcolor=blue, label=\"CL#2003:prev [obj = #53] field#55\"];\n"
				"\t\"11\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#11 [off = 0, TS_FIRST, obj = #8]\"];\n"
				"\t\"11\" -> \"8\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"42\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#42 [off = 0, TS_FIRST, obj = #39]\"];\n"
				"\t\"42\" -> \"39\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"43\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#43 [off = 0, TS_LAST, obj = #39]\"];\n"
				"\t\"43\" -> \"39\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"48\" [shape=ellipse, penwidth=4, fontcolor=black, label=\"#48 [off = 0, obj = #45]\"];\n"
				"\t\"48\" -> \"45\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"4\" -> \"48\" [color=blue, fontcolor=blue];\n"
				"\t\"6\" -> \"42\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely4\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
				"\t\"9\" -> \"lonely4\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely5\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
				"\t\"10\" -> \"lonely5\" [color=blue, fontcolor=blue];\n"
				"\t\"40\" -> \"48\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely6\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
				"\t\"41\" -> \"lonely6\" [color=blue, fontcolor=blue];\n"
				"\t\"46\" -> \"11\" [color=blue, fontcolor=blue];\n"
				"\t\"47\" -> \"43\" [color=blue, fontcolor=blue];\n"
				"\t\"53\" -> \"48\" [color=blue, fontcolor=blue];\n"
				"}";
	}

	static const char *predatorSMGs() {
		return "digraph \"test-0108.c-122-0000\" {\n"
				"\tlabel=<<FONT POINT-SIZE=\"18\">test-0108.c-122-0000</FONT>>;\n"
				"\tclusterrank=local;\n"
				"\tlabelloc=t;\n"
				"subgraph \"cluster1\" {\n"
				"\trank=same;\n"
				"\tlabel=\"SLS 2+, head [+0], next [+0]\";\n"
				"\tcolor=red;\n"
				"\tfontcolor=red;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=3.0;\n"
				"\tstyle=dashed;\n"
				"\t\"9\" [shape=box, color=red, fontcolor=red, label=\"#9 [SC_ON_HEAP, size = 24 B]\"];\n"
				"\t\"10\" [shape=box, color=red, fontcolor=red, penwidth=3.0, style=dashed, label=\".next #10\"];\n"
				"\t\"9\" -> \"10\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"11\" [shape=box, color=black, fontcolor=black, label=\".dll.next #11\"];\n"
				"\t\"9\" -> \"11\" [color=black, fontcolor=black, label=\"[+8]\"];\n"
				"\t\"12\" [shape=box, color=black, fontcolor=black, label=\".dll.prev #12\"];\n"
				"\t\"9\" -> \"12\" [color=black, fontcolor=black, label=\"[+16]\"];\n"
				"}\n"
				"subgraph \"cluster2\" {\n"
				"\trank=same;\n"
				"\tlabel=\"[L1 prototype] DLS 2+, head [+8], next [+8], prev [+16]\";\n"
				"\tcolor=orange;\n"
				"\tfontcolor=orange;\n"
				"\tbgcolor=white;\n"
				"\tpenwidth=3.0;\n"
				"\tstyle=dashed;\n"
				"\t\"14\" [shape=box, color=orange, fontcolor=orange, label=\"#14 [SC_ON_HEAP, size = 24 B]\"];\n"
				"\t\"15\" [shape=box, color=black, fontcolor=black, label=\".data #15\"];\n"
				"\t\"14\" -> \"15\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"16\" [shape=box, color=red, fontcolor=red, penwidth=3.0, style=dashed, label=\".link.next #16\"];\n"
				"\t\"14\" -> \"16\" [color=black, fontcolor=black, label=\"[+8]\"];\n"
				"\t\"17\" [shape=box, color=orange, fontcolor=orange, penwidth=3.0, style=dashed, label=\".link.prev #17\"];\n"
				"\t\"14\" -> \"17\" [color=black, fontcolor=black, label=\"[+16]\"];\n"
				"}\n"
				"\t\"36\" [shape=box, color=blue, fontcolor=blue, label=\"CL#2382:sll [obj = #36] field#38\"];\n"
				"\t\"13\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#13 [off = 0, TS_FIRST, obj = #9]\"];\n"
				"\t\"13\" -> \"9\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
				"\t\"19\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#19 [off = 8, TS_LAST, obj = #14]\"];\n"
				"\t\"19\" -> \"16\" [color=chartreuse2, fontcolor=chartreuse2];\n"
				"\t\"21\" [shape=ellipse, penwidth=3, fontcolor=chartreuse2, label=\"#21 [off = 8, TS_ALL, obj = #9]\"];\n"
				"\t\"21\" -> \"11\" [color=chartreuse2, fontcolor=chartreuse2];\n"
				"\t\"23\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#23 [off = 8, TS_FIRST, obj = #14]\"];\n"
				"\t\"23\" -> \"16\" [color=chartreuse2, fontcolor=chartreuse2];\n"
				"\t\"lonely3\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
				"\t\"10\" -> \"lonely3\" [color=blue, fontcolor=blue];\n"
				"\t\"11\" -> \"23\" [color=blue, fontcolor=blue];\n"
				"\t\"12\" -> \"19\" [color=blue, fontcolor=blue];\n"
				"\t\"lonely4\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
				"\t\"15\" -> \"lonely4\" [color=blue, fontcolor=blue];\n"
				"\t\"16\" -> \"21\" [color=blue, fontcolor=blue];\n"
				"\t\"17\" -> \"21\" [color=blue, fontcolor=blue];\n"
				"\t\"36\" -> \"13\" [color=blue, fontcolor=blue];\n"
				"}";
	}

	static const char *predatorTransformExample() {
		return "digraph \"test-0240.c-52-0000\" {\n"
		"\tlabel=<<FONT POINT-SIZE=\"18\">test-0240.c-52-0000</FONT>>;\n"
		"\tclusterrank=local;\n"
		"\tlabelloc=t;\n"
		"subgraph \"cluster1\" {\n"
		"\trank=same;\n"
		"\tlabel=\"SLS 2+, head [+0], next [+0]\";\n"
		"\tcolor=red;\n"
		"\tfontcolor=red;\n"
		"\tbgcolor=white;\n"
		"\tpenwidth=3.0;\n"
		"\tstyle=dashed;\n"
		"\t\"40\" [shape=box, color=red, fontcolor=red, label=\"#40 [SC_ON_HEAP, size = 8 B]\"];\n"
		"\t\"41\" [shape=box, color=red, fontcolor=red, penwidth=3.0, style=dashed, label=\".next #41\"];\n"
		"\t\"40\" -> \"41\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
		"\t\"42\" [shape=box, color=black, fontcolor=black, label=\".data #42\"];\n"
		"\t\"40\" -> \"42\" [color=black, fontcolor=black, label=\"[+4]\"];\n"
		"}\n"
		"\t\"63\" [shape=box, color=blue, fontcolor=blue, label=\"CL#1984:x [obj = #63] field#71\"];\n"
		"\t\"64\" [shape=box, color=blue, fontcolor=blue, label=\"CL#1985:y [obj = #64] field#77\"];\n"
		"\t\"43\" [shape=ellipse, penwidth=2, fontcolor=chartreuse2, label=\"#43 [off = 0, TS_FIRST, obj = #40]\"];\n"
		"\t\"43\" -> \"40\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
		"\t\"65\" [shape=ellipse, penwidth=1, fontcolor=blue, label=\"#65 VT_OBJECT [off = 0, obj = #64]\"];\n"
		"\t\"65\" -> \"64\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
		"\t\"66\" [shape=ellipse, penwidth=1, fontcolor=blue, label=\"#66 VT_OBJECT [off = 0, obj = #63]\"];\n"
		"\t\"66\" -> \"63\" [color=black, fontcolor=black, label=\"[+0]\"];\n"
		"\t\"lonely2\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
		"\t\"41\" -> \"lonely2\" [color=blue, fontcolor=blue];\n"
		"\t\"lonely3\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
		"\t\"42\" -> \"lonely3\" [color=blue, fontcolor=blue];\n"
		"\t\"63\" -> \"43\" [color=blue, fontcolor=blue];\n"
		"\t\"lonely4\" [shape=plaintext, fontcolor=blue, label=\"NULL\"];\n"
		"\t\"64\" -> \"lonely4\" [color=blue, fontcolor=blue];\n"
		"}";
	};

	static const char *forestAutomata() {
		return "digraph \"test-f0028-fixpoint-0002\" {\n"
				"  label=<<FONT POINT-SIZE=\"18\">test-f0028-fixpoint-0002</FONT>>;\n"
				"  clusterrank=local;\n"
				"  labelloc=t;\n"
				"\n"
				"  subgraph \"cluster_treeaut0\" {\n"
				"    rank=same;\n"
				"    label=\"TA 0\";\n"
				"    labeljust=right;\n"
				"    color=black;\n"
				"    fontcolor=black;\n"
				"    bgcolor=green;\n"
				"    style=dashed;\n"
				"    penwidth=1.0;\n"
				"\n"
				"    subgraph \"cluster_treeaut0_q1_20\" {\n"
				"      rank=same;\n"
				"      label=q1;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"34028696\" [shape=ellipse, style=filled, fillcolor=lightblue, label=\"__global_vars_block\"];\n"
				"      \"34028696.0\" [shape=box, style=filled, fillcolor=pink, label=\"__fake_global__\"];\n"
				"      \"34028696\" -> \"34028696.0\"[label=\"[0:1:+0]\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut0_r0_21\" {\n"
				"      rank=same;\n"
				"      label=r0;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"18446744071866157140\" [shape=box, style=filled, fillcolor=red, label=\"(undef)\"];\n"
				"    }\n"
				"\n"
				"  }\n"
				"\n"
				"  subgraph \"cluster_treeaut1\" {\n"
				"    rank=same;\n"
				"    label=\"TA 1\";\n"
				"    labeljust=right;\n"
				"    color=black;\n"
				"    fontcolor=black;\n"
				"    bgcolor=green;\n"
				"    style=dashed;\n"
				"    penwidth=1.0;\n"
				"\n"
				"    subgraph \"cluster_treeaut1_q24_22\" {\n"
				"      rank=same;\n"
				"      label=q24;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"33979400\" [shape=ellipse, style=filled, fillcolor=lightblue, label=\"main:1971\"];\n"
				"      \"33979400.0\" [shape=box, style=filled, fillcolor=pink, label=\"_pABP\"];\n"
				"      \"33979400\" -> \"33979400.0\"[label=\"[0:4:+0]\"];\n"
				"      \"33979400.4\" [shape=box, style=filled, fillcolor=pink, label=\"_retaddr\"];\n"
				"      \"33979400\" -> \"33979400.4\"[label=\"[4:8:+0]\"];\n"
				"      \"33979400.12\" [shape=box, style=filled, fillcolor=pink, label=\"x\"];\n"
				"      \"33979400\" -> \"33979400.12\"[label=\"[12:4:+0]\"];\n"
				"      \"33979400.16\" [shape=box, style=filled, fillcolor=pink, label=\"y\"];\n"
				"      \"33979400\" -> \"33979400.16\"[label=\"[16:4:+0]\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut1_r0_23\" {\n"
				"      rank=same;\n"
				"      label=r0;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"18446744072865523704\" [shape=box, style=filled, fillcolor=red, label=\"(undef)\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut1_r1_24\" {\n"
				"      rank=same;\n"
				"      label=r1;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"18446744071597073179\" [shape=box, style=filled, fillcolor=red, label=\"(int)0\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut1_r2_25\" {\n"
				"      rank=same;\n"
				"      label=r2;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"18446744072083663336\" [shape=box, style=filled, fillcolor=red, label=\"(native_ptr)0x206ae80\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut1_r3_26\" {\n"
				"      rank=same;\n"
				"      label=r3;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"    }\n"
				"\n"
				"  }\n"
				"\n"
				"  subgraph \"cluster_treeaut2\" {\n"
				"    rank=same;\n"
				"    label=\"TA 2\";\n"
				"    labeljust=right;\n"
				"    color=black;\n"
				"    fontcolor=black;\n"
				"    bgcolor=green;\n"
				"    style=dashed;\n"
				"    penwidth=1.0;\n"
				"\n"
				"    subgraph \"cluster_treeaut2_q22_27\" {\n"
				"      rank=same;\n"
				"      label=q22;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"33775448\" [shape=ellipse, style=filled, fillcolor=lightblue, label=\"T\"];\n"
				"      \"33775448.0\" [shape=box, style=filled, fillcolor=pink, label=\"box0(1)[in=0; out0=4]\"];\n"
				"      \"33775448\" -> \"33775448.0\"[label=\"[0:0:+0]\"];\n"
				"      \"33775448.4\" [shape=box, style=filled, fillcolor=pink, label=\".prev\"];\n"
				"      \"33775448\" -> \"33775448.4\"[label=\"[4:4:+0]\"];\n"
				"      \"33775448.8\" [shape=box, style=filled, fillcolor=pink, label=\".data\"];\n"
				"      \"33775448\" -> \"33775448.8\"[label=\"[8:4:+0]\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut2_q22_28\" {\n"
				"      rank=same;\n"
				"      label=q22;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"33775528\" [shape=ellipse, style=filled, fillcolor=lightblue, label=\"T\"];\n"
				"      \"33775528.0\" [shape=box, style=filled, fillcolor=pink, label=\".next\"];\n"
				"      \"33775528\" -> \"33775528.0\"[label=\"[0:4:+0]\"];\n"
				"      \"33775528.4\" [shape=box, style=filled, fillcolor=pink, label=\".prev\"];\n"
				"      \"33775528\" -> \"33775528.4\"[label=\"[4:4:+0]\"];\n"
				"      \"33775528.8\" [shape=box, style=filled, fillcolor=pink, label=\".data\"];\n"
				"      \"33775528\" -> \"33775528.8\"[label=\"[8:4:+0]\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut2_q25_29\" {\n"
				"      rank=same;\n"
				"      label=q25;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"33685624\" [shape=ellipse, style=filled, fillcolor=lightblue, label=\"T\"];\n"
				"      \"33685624.0\" [shape=box, style=filled, fillcolor=pink, label=\"_pABP\"];\n"
				"      \"33685624\" -> \"33685624.0\"[label=\"[0:4:+0]\"];\n"
				"      \"33685624.8\" [shape=box, style=filled, fillcolor=pink, label=\".data\"];\n"
				"      \"33685624\" -> \"33685624.8\"[label=\"[8:4:+0]\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut2_r0_30\" {\n"
				"      rank=same;\n"
				"      label=r0;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"18446744073289024397\" [shape=box, style=filled, fillcolor=red, label=\"(undef)\"];\n"
				"    }\n"
				"\n"
				"    subgraph \"cluster_treeaut2_r1_31\" {\n"
				"      rank=same;\n"
				"      label=r1;\n"
				"      labeljust=left;\n"
				"      color=black;\n"
				"      fontcolor=black;\n"
				"      bgcolor=orange;\n"
				"      style=dashed;\n"
				"      penwidth=1.0;\n"
				"\n"
				"      \"18446744071898533750\" [shape=box, style=filled, fillcolor=red, label=\"(int)0\"];\n"
				"    }\n"
				"\n"
				"  }\n"
				"\n"
				"  \"34028696.0\" -> \"18446744071866157140\";\n"
				"  \"33979400.0\" -> \"18446744071597073179\";\n"
				"  \"33979400.4\" -> \"18446744072083663336\";\n"
				"  \"33979400.12\" -> \"33775448\";\n"
				"  \"33979400.12\" -> \"33775528\";\n"
				"  \"33979400.16\" -> \"18446744072865523704\";\n"
				"  \"33775448.0\" -> \"33685624\";\n"
				"  \"33775448.4\" -> \"18446744071898533750\";\n"
				"  \"33775448.8\" -> \"18446744073289024397\";\n"
				"  \"33775528.0\" -> \"18446744071898533750\";\n"
				"  \"33775528.4\" -> \"18446744071898533750\";\n"
				"  \"33775528.8\" -> \"18446744073289024397\";\n"
				"  \"33685624.0\" -> \"18446744071898533750\";\n"
				"  \"33685624.8\" -> \"18446744073289024397\";\n"
				"}";
	}

	static void CPACheckerExample(Graph *graph) {
		graph->addNode("init")
			->setHtmlAttr("label","1 Function startu dummy edge<BR />2 int value = 0;");
		graph->addNode("N3")
			->setAttr("shape","diamond")
			->setHtmlAttr("label","N3<BR />6");

		graph->addEdge("init","N3");

		graph->addNode("N5")
			->setHtmlAttr("label","N5<BR />2");
		graph->addNode("N6")
			->setHtmlAttr("label","N6<BR />5")
			->setAttr("shape","diamond");

		graph->addEdge("N3","N5")
			->setAttr("label","[ x > y ]");
		graph->addEdge("N3","N6")
			->setAttr("label","[ !(x > y) ]");

		graph->addNode("N9")
			->setHtmlAttr("label","N9<BR />3");
		graph->addNode("N10")
				->setHtmlAttr("label","N10<BR />4");

		graph->addEdge("N6","N9")
				->setAttr("label","[ x < y ]");
		graph->addEdge("N6","N10")
				->setAttr("label","[ !(x < y) ]");

		graph->addNode("N4")
				->setHtmlAttr("label","N4<BR />1");
		graph->addNode("N0")
				->setHtmlAttr("label","N0<BR />0");

		graph->addEdge("N9","N4")
				->setAttr("label","value = 2;");
		graph->addEdge("N10","N4")
				->setAttr("label","value = 3;");
		graph->addEdge("N4","N0")
				->setAttr("label","return value;");
		graph->addEdge("N5","N4")
				->setAttr("label","value = 1;");

	}

	static void diGraph(Graph *graph) {
		graph->addNode("A")->setAttr("label","a");
		graph->addNode("B")->setAttr("label","b");
		graph->addNode("C")->setAttr("label","c");
		graph->addNode("D")->setAttr("label","d");
		graph->addNode("X")->setAttr("label","x");

		graph->addEdge("A","X");
		graph->addEdge("A","B");
		graph->addEdge("B","C");
		graph->addEdge("B","D");
	}

	static void stdGraph(Graph *graph) {
		graph->setType(std_graph);

		graph->addNode("A")->setAttr("label","a");
		graph->addNode("B")->setAttr("label","b");
		graph->addNode("C")->setAttr("label","c");
		graph->addNode("D")->setAttr("label","d");
		graph->addNode("X")->setAttr("label","x");

		graph->addEdge("A","X");
		graph->addEdge("A","B");
		graph->addEdge("B","C");
		graph->addEdge("B","D");
	}

	static void stdSubGraph(Graph *graph) {
		graph->setType(std_graph);

		graph->addNode("A")->setAttr("label","a");
		graph->addNode("B")->setAttr("label","b");
		graph->addNode("C")->setAttr("label","c");
		graph->addNode("D")->setAttr("label","d");

		graph->addEdge("A","B");
		graph->addEdge("B","C");
		graph->addEdge("B","D");
	}
};


#endif //MEMGRAPH_EXAMPLES_H
