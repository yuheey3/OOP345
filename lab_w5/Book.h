////////////////////////////////////////////////
//Name: Yuki Waka
//Student #: 141082180
//Email: ywaka@myseneca.ca
//Date: Oct 10, 2019
////////////////////////////////////////////////
#ifndef _BOOK_H__
#define _BOOK_H__
#include<iostream>
#include <string>
#include<cstring>
namespace sdds {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_year;
		double m_price = 0.0;
		std::string m_descript;
	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		void setPrice(double p);
		Book(const std::string& strBook);
		friend std::ostream& operator << (std::ostream &os, const Book &b);
	};
}
#endif
