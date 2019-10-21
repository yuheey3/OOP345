// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.12.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess
#ifndef __STRING_H__
#define __STRING_H__
#include <iostream>
namespace sdds {
	extern unsigned int g_maxSize;

	class String {
	private:
		 char* string;
	public:
		String(const char* str);
		void display(std::ostream& os);
	};
	std::ostream& operator << (std::ostream& os, String& str);
}
#endif
