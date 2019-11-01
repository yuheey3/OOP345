// Name: Yuki Waka
// Seneca Student ID: 141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Oct.31.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef __CAR_H__
#define __CAR_H__
#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {

	class Car : public Vehicle{
		std::string tag;
		std::string maker;
		std::string m_condition;
		double m_topSpeed;
	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif
