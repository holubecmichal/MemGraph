//
// Created by Michael Holubec on 15.02.16.
//

#ifndef MEMGRAPH_ATTRIBUTES_H
#define MEMGRAPH_ATTRIBUTES_H


#include <map>
#include <string>
#include <vector>
#include "attribute.h"

namespace memgraph {
	typedef std::map<std::string, Attribute *> attributes_map;
	typedef attributes_map::iterator attributes_it;
	typedef std::pair<std::string, Attribute *> attributes_pair;

	typedef std::vector<std::string> string_vector;
	typedef string_vector::iterator string_vector_it;

	class Attributes {
	private:
		attributes_map attrs;

		Attribute *insert(std::string name, Attribute *attr);

		Attribute *setAttr(std::string name);

	public:
		Attributes() { }

		virtual ~Attributes() {
			for (auto i : attrs) {
				Attribute *attr = i.second;
				delete attr;
			}
		}

		Attribute *getAttr(std::string name);

		unsigned long size();

		attributes_it begin();

		attributes_it end();

		void clear();

		void erase(std::string name);

		Attribute *setAttr(Attribute *attr);

		Attribute *setAttr(std::string name, Attribute *attr);

		void setAttrs(Attributes *attrs);

		template<typename T>

		Attribute *setAttr(std::string name, T value, bool null_attr = false) {
			Attribute *attr = getAttr(name);

			if (attr != NULL) {
				attr->setValue(value);
			} else if (null_attr) {
				attr = insert(name, new Attribute(name));
			} else {
				attr = insert(name, new Attribute(name, value));
			}

			return attr;
		}


		template<typename T>
		Attribute *setHtmlAttr(std::string name, T value) {
			Attribute *attr = setAttr(name, value);
			attr->setHtml();
			return attr;
		}

		Attribute &operator[](std::string name) {
			Attribute *attr = getAttr(name);

			if (attr == NULL) {
				attr = setAttr(name);
			}

			return *attr;
		}

		attributes_map *getAttrs() {
			return &attrs;
		}

	};

}


#endif //MEMGRAPH_ATTRIBUTES_H
