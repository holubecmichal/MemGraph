//
// Created by Michael Holubec on 02.03.16.
//

#include "graphviz_plotter.h"
#include "utility.h"
#include <graphviz/gvc.h>
#include <regex>

void GraphvizPlotter::plot() {
	std::string format = getStringOutputFormat();
	std::string filename = path + name + "." + format;

	GVC_t *gvc;
	Agraph_t *g;
	gvc = gvContext();

	g = agmemread(getDot().c_str());

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

	if(g_graph) {
		parse();
	}

	return graph;
}

void GraphvizPlotter::parse() {
	parseGraphAttrs(g_graph, graph);
	parseSubgraphs(g_graph, graph);
	parseNodes(g_graph, graph);
	parseEdges(g_graph, graph);
}

void GraphvizPlotter::parseSubgraphs(Agraph_t *g, GraphComponent *g_component) {
	string_map node_attrs_bak;
	string_map edge_attrs_bak;
	string_map graph_attrs_bak;

	backup(&node_attrs_bak, &walked_node_attrs);
	backup(&edge_attrs_bak, &walked_edge_attrs);
	backup(&graph_attrs_bak, &walked_graph_attrs);

	for(Agraph_t *subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
		Subgraph *subgraph = g_component->addSubgraph(agnameof(subg));
		parseGraphAttrs(subg, subgraph);
		parseSubgraphs(subg, subgraph);
		parseNodes(subg, subgraph);
		parseEdges(subg, subgraph);

		walked_graph_attrs.clear();
		walked_node_attrs.clear();
		walked_edge_attrs.clear();
		restore(&graph_attrs_bak, &walked_graph_attrs);
		restore(&node_attrs_bak, &walked_node_attrs);
		restore(&edge_attrs_bak, &walked_edge_attrs);
	}
}

void GraphvizPlotter::parseGraphAttrs(Agraph_t *g, GraphComponent *g_component) {
	for (auto i : GraphvizAttrs::graph_attrs) {
		Agsym_t *attr = agattr(g, AGRAPH, (char*)i.c_str(), NULL);

		if((attr && !isWalkedObjectAttr(&walked_graph_attrs, i.c_str(), attr->defval))) {
			std::string val(attr->defval);
			if(!aghtmlstr(attr->defval)) {
				val = Utility::escape_quotes(val);
			}

			g_component->setAttr(i.c_str(), val.c_str());
			walked_graph_attrs.insert(std::pair<std::string,std::string>(i, attr->defval));

			if(aghtmlstr(attr->defval)) {
				Attribute *g_attr = g_component->attrs.getAttr(i.c_str());
				g_attr->setHtml();
			}
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

		if(attr && !isWalkedObjectAttr(&walked_node_attrs, i.c_str(), attr->defval)) {
			std::string val(attr->defval);
			if(!aghtmlstr(attr->defval)) {
				val = Utility::escape_quotes(val);
			}

			g_component->setNodeAttr(i.c_str(), val.c_str());
			walked_node_attrs.insert(std::pair<std::string,std::string>(i, attr->defval));

			if(aghtmlstr(attr->defval)) {
				Attribute *g_attr = g_component->getNodeAttrs()->getAttr(i.c_str());
				g_attr->setHtml();
			}
		}
	}

	for (auto i : GraphvizAttrs::edge_attrs) {
		Agsym_t *attr = agattr(g, AGEDGE, (char*)i.c_str(), 0);

		if(attr && !isWalkedObjectAttr(&walked_edge_attrs, i.c_str(), attr->defval)) {
			std::string val(attr->defval);
			if(!aghtmlstr(attr->defval)) {
				val = Utility::escape_quotes(val);
			}

			g_component->setEdgeAttr(i.c_str(), val.c_str());
			walked_edge_attrs.insert(std::pair<std::string,std::string>(i, attr->defval));

			if(aghtmlstr(attr->defval)) {
				Attribute *g_attr = g_component->getEdgeAttrs()->getAttr(i.c_str());
				g_attr->setHtml();
			}
		}
	}
}

void GraphvizPlotter::parseNodes(Agraph_t *g, GraphComponent *g_component) {
	Agnode_t *n = agfstnode(g);
	while (n) {
		if(isWalkedObject(n, &walked_nodes)) {
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

		if(value && !isWalkedObjectAttr(&walked_node_attrs, i, value)) {
			std::string val(value);
			if(!aghtmlstr(value)) {
				val = Utility::escape_quotes(val);
			}

			node->setAttr(i.c_str(), val.c_str());

			if(aghtmlstr(value)) {
				Attribute *g_attr = node->getAttr(i.c_str());
				g_attr->setHtml();
			}
		}
	}
}

void GraphvizPlotter::parseEdges(Agraph_t *g, GraphComponent *g_component) {
	Agnode_t *from_node = agfstnode(g);
	while (from_node) {

		Agedge_t *e = agfstout(g, from_node);
		while(e) {
			if(isWalkedObject(e, &walked_edges)) {
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
		char *value = agget(e,(char*)i.c_str());

		if(value && !isWalkedObjectAttr(&walked_edge_attrs, i, value)) {
			std::string val(value);
			if(!aghtmlstr(value)) {
				val = Utility::escape_quotes(val);
			}

			edge->setAttr(i.c_str(), val.c_str());

			if(aghtmlstr(value)) {
				Attribute *g_attr = edge->getAttr(i.c_str());
				g_attr->setHtml();
			}
		}
	}
}

void GraphvizPlotter::backup(string_map *storage, string_map *walked_attrs) {
	for( auto i : *walked_attrs) {
		storage->insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

void GraphvizPlotter::restore(string_map *storage, string_map *walked_attrs) {
	for( auto i : *storage) {
		walked_attrs->insert(std::pair<std::string,std::string>(i.first,i.second));
	}
}

bool GraphvizPlotter::isWalkedObjectAttr(string_map *attrs, std::string name, std::string value) {
	for(auto i : *attrs) {
		if(i.first == name && i.second == value) {
			return true;
		}
	}

	return false;
}
