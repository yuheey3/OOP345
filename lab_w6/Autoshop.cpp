// Name: Yuki Waka
// Seneca Student ID: 141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Oct.31.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include "Autoshop.h"

namespace sdds {
	sdds::Autoshop & sdds::Autoshop::operator+=(Vehicle * theVehicle)
	{
		// TODO: insert return statement here
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void sdds::Autoshop::display(std::ostream & out) const
	{
		std::cout << "--------------------------------" << std::endl;
		std::cout << "| Cars in the autoshop!        |" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
			(*it)->display(out);
		}
		std::cout << "--------------------------------" << std::endl;
	}
}
