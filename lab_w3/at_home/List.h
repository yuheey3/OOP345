/////////////////////////////////////////////////
//Name: Yuki Waka
//Student# :141082180
//Email ywaka@myseneca.ca
//Date: Sep.30.2019
/////////////////////////////////////////////////
#ifndef _LIST_H__
#define _LIST_H__
#include<iostream>

namespace sdds {

	template <class T, int N>
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
	template<typename L, typename V, typename T, int N>
	class LVList : public List<T, N> {

	public:
		V accumulate(const L& label) const {

			SummableLVPair<L, V> curSum;
			V sumCurList = curSum.getInitialValue();

			for (size_t i = 0; i < ((List < T, N>&)*this).size(); ++i)
			{
				if (label == ((List<T, N>&)*this)[i].key())
					sumCurList = ((List<T, N>&)*this)[i].sum(label, sumCurList);
			}
			return sumCurList;
		}

	};
}
#endif