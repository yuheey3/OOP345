// Name: Yuki Waka
// Seneca Student ID: 141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Oct.31.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include"car.h"
#include <algorithm>

namespace sdds {

	std::string delimeter(std::string line, std::string deli)
	{
		for (char &c : line)
		{
			if (deli.find(c) != std::string::npos) c = ' ';
		}
		return line;
	}

	Car::Car(std::istream& is) {
		const std::string deli = ",";
		std::string line;
		getline(is, line, '\n');
		line = delimeter(line, deli);
		std::stringstream ss(line);

		std::string speed;

		ss >> maker >> m_condition >> speed;
		m_topSpeed = std::atoi(speed.c_str());
	}

	std::string Car::condition() const {
		if (m_condition == "n")
			return  "new";
		else if (m_condition == "u")
			return "used";
		else if (m_condition == "b")
			return "broken";
		else
			return "invalid";
	}

	double Car::topSpeed() const {
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const {
		if (maker != "") {
			out << "| " << std::right << std::setw(10) << maker << " | " << std::left << std::setw(6) << condition()
				<< " | ";
			out.setf(std::ios::fixed);
			out.precision(2);
			out << std::setw(6) << m_topSpeed << " |" << std::endl;
		}
	

	}
}
