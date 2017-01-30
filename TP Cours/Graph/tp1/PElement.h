#include <sstream>
#include <iostream>
#include <string>
using namespace std;

template <class T>
class PElement{
public :
	T* v;
	PElement<T>* s; 

	PElement<T>(T* objet, PElement* suivant)
		:v(objet),s(suivant)
	{}

	static int taille(const PElement<T> *l) {
		if (l != NULL)
			return 1 + taille(l->s);
		else // l est vide
			return 0 ;
	}

	static const string toString(const PElement<T> * p, const char* debut = "( ", const char* separateur = ", ", const char* fin = ")") {
		ostringstream os;
		const PElement<T>* elem = p;
		os << debut;
		if (elem != NULL) {
			while (elem->s != NULL) {
				os << *(elem->v) << separateur;
				elem = elem->s;
			}
			os << *elem->v;
		}
		os << fin;
		return os.str();
	}

	static void insertionOrdonnee(T * a, PElement<T> * &l, bool(*estPlusPetitOuEgal)(const T* a1, const T * a2)) {
		
		if (l != NULL) {
			if (estPlusPetitOuEgal(a, l->v)) {
				l = new PElement<T>(a, l);
			}
			else {
				if (l->s != NULL) {
					insertionOrdonnee(a, l->s, estPlusPetitOuEgal);
				}
				else {
					l->s = new PElement<T>(a, NULL);
				}
			}
		}
	}
};

template <class T>
ostream& operator<<(ostream& os, const PElement<T> *p) {
	return os << PElement<T>::toString(p) << endl;
}