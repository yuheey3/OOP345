// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.20.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess
#ifndef TIMEDEVENTS_H__
#define TIMEDEVENTS_H__
#include <chrono>
#include <iostream>


namespace sdds {

	class TimedEvents {
		static const int obj = 7;

		int numRecord = 0;
		std::chrono::steady_clock::time_point startT;
		std::chrono::steady_clock::time_point endT;
		struct {
			char eventName[20];
			char unitTime[12];
			std::chrono::steady_clock::duration duration;
		} event[obj];
	public:
		TimedEvents(){}
		void startClock();
		void stopClock();
		void recordEvent(const char *);
		friend std::ostream & operator<<(std::ostream &obj, TimedEvents &tm);
	};
}
#endif