/////////////////////////////////////////////////////////////////////////
//
// Bakalářská práce
// Vizualizace datových struktur pro verifikační nástroje
// Michael Holubec
// GNU LGPLv3
//
//////////////////////////////////////////////////////////////////////////

//
// Created by Michael Holubec on 06.03.16.
//

#ifndef MEMGRAPH_UTILITY_H
#define MEMGRAPH_UTILITY_H


#include <iosfwd>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

class Utility {
private:


public:
	// source: http://stackoverflow.com/posts/217605/revisions
	// trim from start
	static inline std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static inline std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static inline std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}

	// source: http://stackoverflow.com/posts/1162786/revisions
	static inline std::string escape_quotes(const std::string &before)
	{
		std::string after;
		after.reserve(before.length() + 4);

		for (std::string::size_type i = 0; i < before.length(); ++i) {
			switch (before[i]) {
				case '"':
				case '\\':
					after += '\\';
					// Fall through.

				default:
					after += before[i];
			}
		}

		return after;
	}
};


#endif //MEMGRAPH_UTILITY_H
