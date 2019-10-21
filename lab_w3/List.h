/////////////////////////////////////////////////
//Name: Yuki Waka
//Student# :141082180
//Email ywaka@myseneca.ca
//Date: Sep.26.2019
/////////////////////////////////////////////////
#ifndef _LIST_H__
#define _LIST_H__
#include<iostream>

namespace sdds {

	template <class T, size_t N>
		class List {
			T array[N];
			size_t count = 0;
		public:
			List() : count{ 0 } {};

			size_t size() const { return count; }

			const T& operator[](size_t i) const
			{
				return array[i];
			}
			void operator+=(const T& tt)
			{
				if (count < N) {
					array[count] = tt;
					count++;
				}
 			}
		};
	}
#endif
