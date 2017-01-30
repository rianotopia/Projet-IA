#pragma once
#include <iostream>
#include <string>

using namespace std;
class GElement
{
public:
	int clef;
	GElement(int _clef);
	operator string()const;
};

inline ostream& operator<< (ostream& os, GElement& g) {
	os << (string)g << endl;
	return os;
}

