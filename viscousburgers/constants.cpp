// This file sets all the constants of the heat equation.  We assume a two-dimensional rectangle with constant temperature sides.  The rectangle is originally heated up to a temperature
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <cstdlib> 

using namespace std;


double u0 = 1.0;
double c = 1.0;
double L = 1.0;
double meu = 2.0;
double ReL=u0*L/meu;

double x_lower = -0.1; //lower limit 
double x_higher = L+0.1; //highest limit of x
int x_spaces = 100; // number of spaces between x_lower and x_higher

//for the discrete points
double delta_x = (x_higher-x_lower)/x_spaces ;
double delta_t = 0.0000005; //seconds

double ReDeltaX = c*delta_x /meu;
double r = meu* delta_t / pow(delta_x,2);

double func(float ubar){
	return (ubar-1)/(ubar+1) - exp(-ubar*ReL);
}



double bisection_search(double umin, double umax){
	double uguess, ymin, ymax, yguess;
	while (umax-umin>0.0001){
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
   if (x > a){
      return 1;
   }
   else {
      return 0;
   }   

}

double initial_conditions(double x){
	return u0*(1 - delta(x,L));

}

void printarray (double arg[], int length, string input) {
  for (int i=0; i<length; i++)
      if (i==0){
         cout << input <<" Start" << "," << arg[i] << ",";
      }else if (i==length-1){
         cout << arg[i] << "," << input <<" End" << ",";
      }else{
         cout << arg[i] << ",";
      }
}






