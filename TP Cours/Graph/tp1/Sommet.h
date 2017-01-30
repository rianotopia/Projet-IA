#pragma once
#include <sstream>
#include "GElement.h"

template <class T>
class Sommet : public GElement
{
public:
	int degre;
	T v;
	Sommet<T>(int clef, const T information, int deg = 0 )
		:GElement(clef),v(information),degre(deg)
	{}

	operator string() const
	{
		ostringstream os;
		os << GElement::clef << ", " << "degre : " << degre << ", " << "V : "<< v ;
		return os.str();
	}
};

template <class T>
ostream& operator<< (ostream& os, Sommet<T>& s) {
	os << (string)s << endl;
	return os;
}
