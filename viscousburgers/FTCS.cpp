// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation

#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include <cmath>
#include "constants.h"



using namespace std;

int main(int argc, char **argv){
	double x_values [x_spaces+1];
	double u_values [x_spaces+1]; //n+1
	double u_values_old [x_spaces+1]; //n
	
	double u_fwd, u_back, u_on;

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
		u_values_old[i] = initial_conditions(x_values[i]);
	}

	int loop = 0;
	while (loop < 100000){
		for (int i=0; i<=x_spaces;i++){

			if (i==0 || x_values[i]<=0){
				u_fwd = u0;
				u_on = u0;
				u_back = u0;
			} if (i==x_spaces ||  x_values[i]>=L){
				u_fwd = 0;
				u_on = 0;
				u_back = u_values_old[i-1];
			} else {
				u_fwd = u_values_old[i+1];
				u_on = u_values_old[i];
				u_back = u_values_old[i-1];
			}

			u_values[i] = r/2.0*(2-ReDeltaX)*u_fwd + (1-2*r)*u_on + r/2.0*(2+ReDeltaX)*u_back;

		}


		for (int i=0; i<=x_spaces;i++){
			u_values_old[i] = u_values[i];
			if (x_values[i]<=0){
				u_values_old[i] = u0;
			} else if (x_values[i]>=L){
				u_values_old[i] = 0;
			}
		}
		loop += 1;
	}
	printarray(x_values,x_spaces+1,"X FTCS");
	printarray(u_values,x_spaces+1,"Y FTCS");
	return 0;
}
