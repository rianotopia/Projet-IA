#include <stdlib.h>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "recuitSimule.h"
#include "Vecteur2D.h"

using namespace std;

double changementAleatoire(const double& x) { return x + alea() - 0.5 ; }
double succ(const double& t) { return t - 1; }

/*x -> f(x) = (x-2)²+3 */
double f(const double& x) { return ((x - 2)*(x - 2) + 3); }

/* x -> f(x) = -5(cos(wx)/1+|x|) avec w = 2pi */
double f2(const double& x) { return (-5*(cos(2 * M_PI * x)/(1 + abs(x)))); }

Vecteur2D changementAleatoireVecteur(const Vecteur2D& v) { 
	return Vecteur2D(v.x + alea() - 0.5, v.y + alea() - 0.5);
}

/* (x,y) -> f(x,y) = (x-2)² + (y-2)² + 3 */
double f3(const Vecteur2D& v) { return ((v.x - 2)*(v.x - 2) + (v.y - 2)*(v.y - 2) + 3); }

/* (x,y) -> f(x,y) = -2(cos(wr)/1+r) avec r = (x²+y²)^1/2 et w = 2pi */
double f4(const Vecteur2D& v) {
	double r = sqrt(pow(v.x,2) + pow(v.y,2));
	double w = 2 * M_PI;
	return -2 * (cos(w*r) / 1 + r);
}

int main() {
	srand((unsigned)time(NULL));
	double sol = 0;
	double tInitial = 100;
	double tFinal = 0;
	int nombreTentativeMax = 100; 
	int nombreSuccesMax = 100;

	/*Ex2*/
	//sol = recuitSimule(tInitial, tFinal, nombreTentativeMax, nombreSuccesMax, sol, f, changementAleatoire, succ);
	//cout <<"Réesultat : f1(" << sol << ") = " << f(sol) << endl;

	/*Ex3*/
	//sol = 0;
	//sol = recuitSimule(tInitial, tFinal, nombreTentativeMax, nombreSuccesMax, sol, f2, changementAleatoire, succ);
	//cout << "Resultat : f2(" << sol << ") = " << f2(sol) << endl;

	/*Ex4*/
	Vecteur2D SolutionVecteur2D = Vecteur2D(0, 0);
	//SolutionVecteur2D = recuitSimule(tInitial, tFinal, nombreTentativeMax, nombreSuccesMax, SolutionVecteur2D, f3, changementAleatoireVecteur, succ);
	//cout << "Resultat : f3" << SolutionVecteur2D << " = " << f3(SolutionVecteur2D) << endl;

	/*Ex5*/
	SolutionVecteur2D = Vecteur2D(0, 0);
	SolutionVecteur2D = recuitSimule(tInitial, tFinal, nombreTentativeMax, nombreSuccesMax, SolutionVecteur2D, f4, changementAleatoireVecteur, succ);
	cout << "Resultat : f4" << SolutionVecteur2D << " = " << f4(SolutionVecteur2D) << endl;

	system("pause");
	return 0;
}