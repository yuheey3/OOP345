// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// w1.cpp
// Chris Szalwinski - 2019/01/08
// Cornel - 2019/09/06

// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.12.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess

#include <iostream>
#include "process.h"
#include "String.h"
using namespace sdds;

// TODO: write the prototype for the main function
//         to accept command line arguments
int main(int argc, char **argv)
{
	std::cout << "Command Line:\n";


	// TODO: print the command line here, in the format
	// 1: first argument
	// 2: second argument
	// 3: third argument



	if (argc < 2)
	{
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		return 1;
	}
	else {
		for (int i = 0; i < argc; i++) {
			std::cout << i + 1 << ": " << argv[i] << std::endl;
		}
	}
	std::cout << std::endl;



	std::cout << "------------------\n";
	std::cout << "Global variable:\n";
	std::cout << "------------------\n";
	std::cout << "Old Value: " << sdds::g_maxSize << '\n';
	sdds::g_maxSize = 4;
	std::cout << "New Value: " << sdds::g_maxSize << '\n';
	std::cout << "------------------\n\n";

	std::cout << "------------------\n";
	std::cout << "Processing:\n";
	std::cout << "------------------\n";
	for (int i = 1; i < argc; i++)
		sdds::process(argv[i]);
	std::cout << "------------------\n\n";

	return 0;
}