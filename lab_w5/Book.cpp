////////////////////////////////////////////////
//Name: Yuki Waka
//Student #: 141082180
//Email: ywaka@myseneca.ca
//Date: Oct 10, 2019
////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <iomanip>
#include"Book.h"
#include<cstring>
namespace sdds {

	Book::Book() {
		m_author = "";
		m_title = "";
		m_country = "";
		m_year = 0;
		m_price = 0.0;
		m_descript = "";
	}
	const std::string& Book::title() const { return m_title; }

	const std::string& Book::country() const { return m_country; }

	const size_t& Book::year() const { return m_year; }
	double& Book::price() { return m_price; }

	void Book::setPrice(double p) {
		m_price = p;
	}

	Book::Book(const std::string& strBook) {

		size_t start = 0;
		size_t end = strBook.find(",");

		m_author = strBook.substr(start, end);

		if (m_author.size() > 0)
		{
			start = end + 1;
			end = strBook.find(",", start);
			std::string temp = strBook.substr(start, end - start);

			std::size_t first = temp.find_first_not_of(' ');
			std::size_t last = temp.find_last_not_of(' ');
			m_title = temp.substr(first, last - first + 1);
		}


		if (m_title.size() > 0) {
			start = end + 1;
			end = strBook.find(",", start);
			std::string temp = strBook.substr(start, end - start);

			char *temp2 = new char[temp.length() + 1];
			strcpy(temp2, temp.c_str());
			char *temp3 = new char[strlen(temp2) + 1];

			size_t k = 0;
			for (size_t i = 0; i < strlen(temp2); i++) {

				if (temp2[i] != ' ') {
					temp3[k] = temp2[i];
					k++;
				}
			}
			temp3[k] = '\0';
			m_country = temp3;
		}
		if (m_country.size() > 0) {
			start = end + 1;
			end = strBook.find(",", start);
			std::string temp = strBook.substr(start, end - start);

			char *temp2 = new char[temp.length() + 1];
			strcpy(temp2, temp.c_str());
			char *temp3 = new char[strlen(temp2) + 1];

			size_t k = 0;
			for (size_t i = 0; i < strlen(temp2); i++) {

				if (temp2[i] != ' ') {
					temp3[k] = temp2[i];
					k++;
				}
			}
			temp3[k] = '\0';
			m_price = std::stod(temp3);
		}


		if (m_price > 0) {
			start = end + 1;
			end = strBook.find(",", start);
			std::string temp = strBook.substr(start, end - start);

			char *temp2 = new char[temp.length() + 1];
			strcpy(temp2, temp.c_str());
			char *temp3 = new char[strlen(temp2) + 1];

			size_t k = 0;
			for (size_t i = 0; i < strlen(temp2); i++) {

				if (temp2[i] != ' ') {
					temp3[k] = temp2[i];
					k++;
				}
			}
			temp3[k] = '\0';
			m_year = std::atoi(temp3);
		}

		if (m_year > 0) {
			start = end + 1;
			end = strBook.length();
			std::string temp = strBook.substr(start, end - start);

			std::size_t first = temp.find_first_not_of(' ');
			std::size_t last = temp.find_last_not_of(' ');
			m_descript = temp.substr(first, last - first + 1);
		}

	}

	std::ostream& operator << (std::ostream &os, const Book& b) {
		os << std::setw(20) << b.m_author << " | " << std::setw(22)
			<< b.m_title << " | " << std::setw(5) << b.m_country
			<< " | " << std::setw(4) << b.year() <<
			" | ";
		os.setf(std::ios::fixed);
		os.precision(2);
		os << std::setw(6) << b.m_price << " | " << b.m_descript << std::endl;
		return os;
	}
}

