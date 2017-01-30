#include <iostream>
#include <math.h>

using namespace std;

double carre(const double & x){return x*x;}
double racineCarre(const double & x){return sqrt(x);}
int main() {
	cout << "Exemple d'utilisation de pointeur de fonction" << endl << endl;
	double(*f)(const double & x);
	f = carre; 
	double t = 4; 
	double ft;
	ft = f(t);
	cout << "t = " << t << ", f(t) = " << ft << endl << endl;
	cout << " quel fonction a été initialisée, carre(..) ou racineCarre(...) ?" << endl << endl;

	f = racineCarre;
	ft = f(t);
	cout << "t = " << t << ",f(t) = " << ft << endl << endl;
	cout << " quel fonction a été initialisée, carre(..) ou racineCarre(...) ?" << endl << endl;
	system("pause");
	return 0;
}