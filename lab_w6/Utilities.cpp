// Name: Yuki Waka
// Seneca Student ID: 141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Oct.31.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <string>
#include <sstream>
#include "Utilities.h"
namespace sdds {

	sdds::Vehicle* createInstance(std::istream& in) {
		std::string line;
		getline(in, line, '\n');
		std::stringstream ss(line);
		char type;
		char delim;
		ss >> type >> delim;

		if (type == 'c' || type == 'C')
			return new Car(ss);
		else
			return nullptr;
	};
}