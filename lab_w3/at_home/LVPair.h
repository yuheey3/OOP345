/////////////////////////////////////////////////
//Name: Yuki Waka
//Student# :141082180
//Email ywaka@myseneca.ca
//Date: Sep.30.2019
/////////////////////////////////////////////////
#ifndef _LVPAIR_H__
#define _LVPAIR_H__
#include <iostream>
#include <string>

namespace sdds {

	template <typename L, typename V>
	class LVPair {
		L mlabel;
		V mvalue;
	public:
		LVPair() {};
		LVPair(const L& aa, const V& bb) { mlabel = aa; mvalue = bb; };
		const L& key() const { return mlabel; };
		const V& value() const { return mvalue; };
		virtual void display(std::ostream& os) const
		{
			os << mlabel << " : " << mvalue << std::endl;
		};
	};
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	};


	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V sumInit;
		static size_t min;
	public:
		static const V& getInitialValue() { return sumInit; }

		SummableLVPair() {}
		SummableLVPair(const L& lbl, const V& val)
			:LVPair<L, V>(lbl, val)
		{
			if (min < lbl.size())
				min = lbl.size();
		}

		V sum(const L& lbl, const V& val) const
		{
			if (LVPair<L, V>::key() == lbl) {
				return LVPair<L, V>::value() + val;
			}
			else return val;
		}

		void display(std::ostream& os) const
		{
			os.setf(std::ios::left);
			os.width(min);
			os << LVPair<L, V>::key() << " : " << LVPair<L, V>::value() << std::endl;
			os.setf(std::ios::left);
		}
	};
	template <typename L, typename V>
	size_t SummableLVPair <L, V>::min = 0;


	template<>
	std::string SummableLVPair<std::string, std::string>::sumInit = "";


	template<>
	int SummableLVPair<std::string, int>::sumInit = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::sum
	(const std::string& lbl, const std::string& val) const {
		if (val != "")
			return (val + ", " + value());
		else
			return val + value();

	}
}

#endif