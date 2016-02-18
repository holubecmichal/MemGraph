#include <iostream>
#include "attribute.h"
#include "attributes.h"
#include "node.h"
#include "edge.h"

using namespace std;

int main() {
	attribute attr_i(10);
	attribute attr_d(10.333);
	attribute attr_s("Hello worlddddddd");
	attribute attr_b(true);

	attributes attrs;
	attrs.setAttr("string", attr_s);
	attrs.setAttr("new_string", "ahoooj");
	attrs.setAttr("int", 10);
	attrs.setAttr("double", 10.323232);

	attribute *attr = attrs.getAttr("string");

	node from("from");
	from.attrs.setAttr("string", "ahooj");
	from.attrs.setAttr("int", 10);
	from.attrs.setAttr("double", 5.3);

	node to("to");
	to.attrs.setAttr("string", "zdaaar");
	to.attrs.setAttr("int", 24);
	to.attrs.setAttr("double", 1.89);

	edge edge_1(&from, &to);
	edge_1.attrs.setAttr("nejaky atribut", "den je krasny");

	cout << attr->s_value << endl;

	return 0;
}