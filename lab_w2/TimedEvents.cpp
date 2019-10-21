// Name: Yuki Waka
// Seneca Student ID:141082180
// Seneca email: ywaka@myseneca.ca
// Date of completion: Sep.19.2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my profess
#include<iostream>
#include <chrono>
#include<iomanip>
#include<cstring>
#include"TimedEvents.h"
#include"Text.h"
#define _CRT_SECURE_NO_WARNINGS

namespace sdds {

	void TimedEvents::startClock()
	{
		startT = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		endT = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char *reName)
	{
		strncpy(event[numRecord].eventName, reName, strlen(reName));
		event[numRecord].eventName[strlen(reName)] = '\0';
		strcpy(event[numRecord].unitTime, "nanoseconds");
		event[numRecord].unitTime[12] = '\0';
		event[numRecord].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endT - startT);
		numRecord++;
	}

	std::ostream & operator<<(std::ostream &obj, TimedEvents &tm)
	{
		obj << "--------------------------\n";
		obj << "Execution Times:\n";
		obj << "--------------------------\n";
		for (int i = 0; i < tm.numRecord; i++)
			obj << std::setw(20) << std::left << tm.event[i].eventName << std::setw(12) << std::right
			<< tm.event[i].duration.count() << std::setw(12) << std::right << tm.event[i].unitTime << '\n';
		obj << "--------------------------\n";
		return obj;
	}
}
