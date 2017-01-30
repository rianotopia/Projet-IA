#pragma once

#include <iostream>
#include <string>
#include "PElement.h"

using namespace std;


bool estPlusPetitOuEgal(const double* a, const double* b) {
	if (*a <= *b) {
		return true;
	}
	else {
		return false;
	}
}

bool estPlusPetitOuEgalString(const string* a, const string* b) {
	if (a->compare(*b) >= 0) {
		return true;
	}
	else {
		return false;
	}
}

int main1() {
	PElement<double>* l1;
	PElement<string>* l2;

	l1 = new PElement<double>(new double(9), NULL);
	l1 = new PElement<double>(new double(7.5), l1);
	l1 = new PElement<double>(new double(5), l1);
	l1 = new PElement<double>(new double(2), l1);

	l2 = new PElement<string>(new string("orange"), NULL);
	l2 = new PElement<string>(new string("cerise"), l2);
	l2 = new PElement<string>(new string("carotte"), l2);
	
	cout << "Taille de l1 : " << PElement<double>::taille(l1) << endl;
	cout << "Taille de l2 : " << PElement<string>::taille(l2) << endl;

	cout << "l1 : " << l1 << endl;
	cout << "l2 : " << l2 << endl;

	PElement<double>::insertionOrdonnee(new double(-7), l1, estPlusPetitOuEgal);
	PElement<double>::insertionOrdonnee(new double(6), l1, estPlusPetitOuEgal);
	PElement<double>::insertionOrdonnee(new double(13), l1, estPlusPetitOuEgal);
	PElement<double>::insertionOrdonnee(new double(11), l1, estPlusPetitOuEgal);

	PElement<string>::insertionOrdonnee(new string("fraise"), l2, estPlusPetitOuEgalString);
	PElement<string>::insertionOrdonnee(new string("ananas"), l2, estPlusPetitOuEgalString);
	PElement<string>::insertionOrdonnee(new string("pomme"), l2, estPlusPetitOuEgalString);

	cout << "l1 : " << l1 << endl;
	cout << "l2 : " << l2 << endl;

	system("pause");
	return 0;

}