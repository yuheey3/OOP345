/////////////////////////////////////////////////
//Name: Yuki Waka
//Student# :141082180
//Email ywaka@myseneca.ca
//Date: Oct.3.2019
/////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Reservation.h"
#include<string>
#include <cstring>
#include <stdlib.h>
namespace sdds {

	Reservation::Reservation()
	{
		resId = nullptr;
		mName = "";
		mEmail = "";
		pplNum = 0;
		mDay = 0;
		mHour = 0;
		meal = "";
	}
	Reservation::Reservation(const std::string& m_res) {


		size_t start = 0;
		size_t end = m_res.find(":");

		std::string t_res = m_res.substr(start, end);

		char *temp2 = new char[t_res.length() + 1];
		strcpy(temp2, t_res.c_str());
		resId = new char[strlen(temp2) + 1];

		size_t k = 0;
		for (size_t i = 0; i < strlen(temp2); i++) {

			if (temp2[i] != ' ') {
				resId[k] = temp2[i];
				k++;
			}
		}
		resId[k] = '\0';

		if (resId[0] != '\0')
		{
			start = end + 1;
			end = m_res.find(",", start);
			std::string temp = m_res.substr(start, end - start);

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
			mName = temp3;
		}


		if (mName.size() > 0)
		{
			start = end + 1;
			end = m_res.find(",", start);
			std::string temp = m_res.substr(start, end - start);

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
			mEmail = temp3;
			mEmail.insert(mEmail.begin(), '<');
			mEmail.append(1, '>');
		}


		if (mEmail.size() > 0)
		{
			start = end + 1;
			end = m_res.find(",", start);
			std::string temp = m_res.substr(start, end - start);

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
			pplNum = std::atoi(temp3);
		}

		if (pplNum > 0)
		{
			start = end + 1;
			end = m_res.find(",", start);
			std::string temp = m_res.substr(start, end - start);

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
			mDay = std::atoi(temp3);
		}

		if (mDay > 0)
		{
			start = end + 1;
			end = m_res.length();
			std::string temp = m_res.substr(start, end - start);

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
			mHour = std::atoi(temp3);
		}

		if (mHour >= 6 && mHour <= 9)
			meal = "Breakfast";
		else if (mHour >= 11 && mHour <= 15)
			meal = "Lunch";
		else if (mHour >= 17 && mHour <= 21)
			meal = "Dinner";
		else
			meal = "Drinks";
	}

	std::ostream& operator << (std::ostream &os, const Reservation& r) {
		os << "Reservation " << r.resId << ": " << std::setw(10) << std::right << r.mName << "  "
			<< std::setw(20) << std::left << r.mEmail << "    " << r.meal << " on day " << r.mDay << " @ " << r.mHour
			<< ":00 " << "for " << r.pplNum << " people." << std::endl;
		return os;
	}
}