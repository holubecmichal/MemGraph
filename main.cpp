#include <iostream>
#include "attribute.h"
#include "attributes.h"
#include "node.h"
#include "edge.h"

using namespace std;

int main() {
	node *Node = new node("node 1");
	edge *Edge = new edge();

	Node->setName("prvni node");

	Node->setAttr("string_1", "ahoooj");
	Node->setAttr("string_2", "nazdaaar");

	Edge->setFrom(Node);

	Node = new node("node 2");
	Node->setAttr("asd", 10);
	Node->setAttr("bflm", true);
	Node->setAttr("psvz", "aeiou");

	Edge->setTo(Node);

	cout << Edge->getFrom()->getAttr("string_1")->getSValue() << endl;
	cout << Edge->getFrom()->getAttr("string_2")->getSValue() << endl;
	cout << Edge->getTo()->getAttr("psvz")->getSValue() << endl;

	return 0;
}