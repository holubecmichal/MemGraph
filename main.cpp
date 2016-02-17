#include <iostream>
#include "attribute.h"

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

	return 0;
}