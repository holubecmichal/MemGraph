//
// Created by Michael Holubec on 06.03.16.
//

#ifndef BACHELOR_UTILITY_H
#define BACHELOR_UTILITY_H


#include <iosfwd>
#include <vector>
#include <string>
#include <sstream>

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
};


#endif //BACHELOR_UTILITY_H