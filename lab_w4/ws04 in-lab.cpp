// Workshop 4 - Containers
// 2019/09/27 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Reservation.h"


int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n";

	sdds::Reservation** ppReservations = nullptr;
	size_t cnt = 0;

	// Process the file
	{
		std::ifstream file(argv[1]);
		if (!file)
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			return 1;
		}

		std::string strReservation;
		// count how many records are in the file
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
					++cnt;
			}
		} while (file);

		ppReservations = new sdds::Reservation*[cnt];
		cnt = 0;

		// read again from the file, but this time load and store data
		file.clear();
		file.seekg(std::ios::beg);
		do
		{
			std::getline(file, strReservation);

			// if the previous operation failed, the "file" object is
			//   in error mode
			if (file)
			{
				// Check if this is a commented line.
				//   In the input file, commented lines start with '#'
				if (strReservation[0] != '#')
				{
					ppReservations[cnt] = new sdds::Reservation(strReservation);
					++cnt;
				}
			}
		} while (file);
		file.close();
	}
	std::cout << "\nReservations\n--------------------------\n";
	for (auto i = 0u; i < cnt; ++i)
	{
		std::cout << *ppReservations[i];
	}
	std::cout << "--------------------------\n\n";

	// cleanup
	for (auto i = 0u; i < cnt; ++i)
		delete ppReservations[i];
	delete[] ppReservations;

	return 0;
}