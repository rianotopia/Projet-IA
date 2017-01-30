#include "GElement.h"
#include <sstream>

GElement::GElement(int _clef)
	:clef(_clef)
{
}

GElement::operator string() const
{
	ostringstream os;
	os << clef;
	return os.str();
}