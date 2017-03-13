/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 15.02.16.
//

#include "edge.h"
#include "graph_component.h"

namespace memgraph {
	string_vector Edge::available_attrs;

	void Edge::setFrom(Node *node) {
		if(node == NULL) {
			throw "node is null";
		}

		from = node;
	}

	Node *Edge::getFrom() {
		return from;
	}

	void Edge::setTo(Node *node) {
		if(node == NULL) {
			throw "node is null";
		}

		to = node;
	}

	Node *Edge::getTo() {
		return to;
	}

	Attribute *Edge::getAttr(std::string name) {
		return attrs.getAttr(name);
	}

	void Edge::setAttrs(Attributes *new_attrs) {
		for (auto i : *new_attrs) {
			checkAttr(i.first);
		}
		attrs.setAttrs(new_attrs);
	}

	bool Edge::isAvailableAttr(std::string name) {
		if(name.length() == 0) {
			throw "identificator is not set";
		}

		if (available_attrs.size() == 0) {
			return true;
		}

		for (auto i : available_attrs) {
			if (i == name) {
				return true;
			}
		}

		return false;
	}

	void Edge::checkAttr(std::string name) {
		if (!isAvailableAttr(name) && GraphComponent::enable_warnings) {
			printWarning(name);
		}
	}

	void Edge::printWarning(std::string name) {
		std::cerr << "Edge: Unknown atribute " << name << std::endl;
	}
}
