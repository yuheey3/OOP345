/////////////////////////////////////////////////
/////////////////////////////////////////////////
//Name: Yuki Waka
//Student# :141082180
//Email ywaka@myseneca.ca
//Date: Oct.3.2019
/////////////////////////////////////////////////
#ifndef __RESERVATION_H__
#define __RESERVATION_H__
#include<iostream>
#include <iomanip>

namespace sdds {
	class Reservation {
		char *resId;
		std::string mName;
		std::string mEmail;
		std::string meal;
		int pplNum;
		int mDay;
		int mHour;
	public:
		Reservation();
		Reservation(const std::string& m_res);
		friend std::ostream& operator << (std::ostream &os, const Reservation &r);
	};
}
#endif

