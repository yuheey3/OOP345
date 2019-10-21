// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.20.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess
#include<iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>
#include"TimedEvents.h"
#include"Text.h"

namespace sdds
{
	Text::Text()
	{
		this->count = 0;
	}
	Text::Text(char* file)
	{
		std::ifstream fp;
		fp.open(file);
		if (fp) {
			while (!fp.eof())
			{
				if (fp.get() == ' ')
					count++;
			}
			str = new std::string[count];
			str = dynamic_cast<std::string*>(fp.rdbuf());
			fp.close();
		}
	}

	Text::Text(Text& arr)
	{
		*this = arr;
	}

	Text::Text(Text&& arr)
	{
		this->str = std::move(arr.str);
		this->count = std::move(arr.count);
	}

	Text& Text::operator = (Text& arr)
	{
		if (this != &arr) {
		
			str = new std::string[arr.count];

			for (size_t i = 0; i < (size_t)count; i++)
			{
				str[i] = arr.str[i];
			}
			count = arr.count;
		}
		return *this;
	}
	Text& Text::operator = (Text&& arr)
	{
		if (this != &arr) {
			str = arr.str;
			count = arr.count;
			arr.str = nullptr;
		}
		return *this;
	}

	Text::~Text()
	{
		delete[] str;
		count = 0;
	}
	
	size_t Text::size() const
	{
		return this->count;
	}
}