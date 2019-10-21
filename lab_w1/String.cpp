// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.12.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "String.h"


namespace sdds {
	int counter = 0;
	unsigned int g_maxSize = 3;

	String::String(const char* str) {
		if (str != nullptr)
		{
			string = new char[g_maxSize];
			strcpy(string, str);
			string[g_maxSize-1] = '\0';
		
		}
		else {
			//string[0] = '\0';
			//delete[] string;
		}
	}
	void String::display(std::ostream& os)
	{
		os << string;
	}
	std::ostream& operator << (std::ostream& os, String& str) {

		counter++;
	
		os << counter;
		os << ": ";
		str.display(os);
		return os;
	}
}