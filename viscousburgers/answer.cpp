// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include "constants.h"

using namespace std;

double analytical_answer(float x, float ubar){
	return u0*ubar*(1.0- exp(ubar*ReL*(x/L-1.0)))/(1.0+exp(ubar*ReL*(x/L-1.0)));

}

int main(int argc, char **argv){
	double x_values [x_spaces+1];
	double u_values [x_spaces+1];
	double umin = 0;
	double umax = 10.0;
	double ubar = bisection_search(umin, umax);

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values[i] = analytical_answer(x_values[i],ubar); 
	}

	printarray(x_values,x_spaces+1,"X Values");
	printarray(u_values,x_spaces+1,"Y Values");

	return 0;

}
