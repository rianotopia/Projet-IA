#pragma once

#include <iostream>
#include <string>
#include "GElement.h"
#include "Sommet.h"
#include "Arete.h"

using namespace std;

int main() {
	GElement g = GElement(1);

	Sommet<double>* s1 = new Sommet<double>(2, 5);
	Sommet<string>* s3 = new Sommet<string>(4, "Hello");
	Sommet<string>* s2 = new Sommet<string>(3, "Hello");

	cout << "s1 : " << s1 << endl;
	cout << "s2 : " << s2 << endl;

	Arete<string, char> a1 = Arete<string,char>(5, s2, s3, 'a');

	system("pause");
	return 0;
}