/////////////////////////////////////////////////
//Name: Yuki Waka
//Student# :141082180
//Email ywaka@myseneca.ca
//Date: Sep.26.2019
/////////////////////////////////////////////////
#ifndef _LVPAIR_H__
#define _LVPAIR__
#include <iostream>


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
		void display(std::ostream& os) const
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

}
#endif