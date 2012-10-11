// This file sets all the constants of the heat equation.  We assume a two-dimensional rectangle with constant temperature sides.  The rectangle is originally heated up to a temperature
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


double u0 = 1;
double L = 1;
double meu = 1;
double ReL=u0*L/meu;

double func(float ubar){
	return (ubar-1)/(ubar+1) - exp(-ubar*ReL);
}



double bisection_search(double umin, double umax){
	double uguess, ymin, ymax, yguess;
	while (umax-umin>0.1){
		uguess = (umin + umax)/2;

		ymin = func(umin);
		yguess = func(uguess);
		ymax = func(umax);

		if (yguess > 0){
			umax = uguess;
		} else if (yguess < 0){
			umin = uguess;
		} else if (yguess == 0){
			return uguess;
		}
	}
	
	return uguess;
}


int delta(float x, float a){
   if (x >= a){
      return 1;
   }
   else {
      return 0;
   }   

}

double initial_conditions(double x){
	return u0;

}






