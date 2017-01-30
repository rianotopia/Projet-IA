#pragma once
#include "GElement.h"
#include "Sommet.h"

template <class S, class T>
class Arete : public GElement
{
public:
	Sommet<T> *debut, *fin;
	S v;
	Arete<S,T>(int clef, Sommet<T>* deb,Sommet<T>* fi, S instance )
		:GElement(clef),debut(deb),fin(fi),v(instance)
	{
	}

	operator string() const
	{
		ostringstream os;
		os << GElement::clef << ", " << "Clef S1 : " << *(debut->clef) << ", Clef S1 : " << *(debut->clef) << ", info : " << v;
		return os.str();
	}

};

template <class T, class S>
ostream& operator<< (ostream& os, Arete<S,T>& a) {
	os << (string)a << endl;
	return os;
}