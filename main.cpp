#include <iostream>
#include "attribute.h"
#include "attributes.h"

using namespace std;

int main() {
	attribute<int> attr_i(10);
	attribute<double> attr_d(10.333);
	attribute<std::string> attr_s("ahooooj");
	attribute<bool> attr_b(true);

	cout << attr_i.getValue() << endl;
	cout << attr_d.getValue() << endl;
	cout << attr_s.getValue() << endl;
	cout << attr_b.getValue() << endl;

	attributes attrs;
	attrs.setAttr("int", 10);
	attrs.setAttr("double", 10.3);
	attrs.setAttr("string", "asd");
	attrs.setAttr("bool", true);

	//attrs.getAttr("string");

	return 0;
}