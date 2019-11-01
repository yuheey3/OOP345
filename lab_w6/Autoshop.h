// Name: Yuki Waka
// Seneca Student ID: 141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Oct.31.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef __AUTOSHOP_H__
#define __AUTOSHOP_H__
#include <string>
#include <sstream>
#include <vector>
#include "Vehicle.h"
#include "car.h"

namespace sdds {

	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
	};
}

#endif
