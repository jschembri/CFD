// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include "constants.h"

using namespace std;

int main(int argc, char **argv){
   double x = atof(argv[1]);
	double umin = 0;
	double umax = 10;
	double ubar = bisection_search(umin, umax);

	cout << u0*ubar*(1- exp(ubar*ReL*(x/L-1)))/(1+exp(ubar*ReL*(x/L-1)));
	return 0;

}
