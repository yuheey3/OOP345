// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.20.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess
#ifndef TEXT_H__
#define TEXT_H__
#include <fstream>
#include <string>

namespace sdds {

	class Text {
		int count = 0;
		std::string *str;
	public:
		Text();
		Text(char*);
		Text(Text&);
		Text(Text&&);
		Text& operator = (Text&);
		Text& operator = (Text&&);
		~Text();
		size_t size() const;
	};
}
#endif
