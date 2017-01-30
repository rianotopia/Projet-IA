#pragma once
#include <time.h>  
double alea() {
	double t = rand();
	return t/RAND_MAX;
}

template <class S>
S recuitSimule(const double& tInitial, 
					const double& tFinal, 
					const int& nombreTentativesMax,
					const int& nombreSuccesMax,
					const S s0,
					double (*cout1)(const S& s), 
					S (*changementAleatoire)(const S& s), 
					double (*succ)(const double& t )) {

	double t = tInitial;
	S s = s0;
	S sBest = s0;
	S sPrec;
	int nombreTentatives;
	int nombreSucces;
	while (t > tFinal) {
		nombreTentatives = 0;
		nombreSucces = 0;
		while (nombreTentatives < nombreTentativesMax && nombreSucces < nombreSuccesMax) {
			nombreTentatives++;
			sPrec = s;
			s = changementAleatoire(s);
			if (cout1(s) < cout1(sPrec)) {
				nombreSucces++;
				if (cout1(s) < cout1(sBest))
					sBest = s;
			}
			else {
				double v = alea();
				double deltaCout = cout1(s) - cout1(sPrec);
				double expo = exp(-(deltaCout / t));
				if (v < expo ) {
					nombreSucces++;
				}
				else {
					s = sPrec;
				}
			}
		}
		if (nombreSucces = 0) {
			return sBest;
		}
		t = succ(t);
	}
	return sBest;
}