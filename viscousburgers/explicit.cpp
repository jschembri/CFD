// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation

#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include <cmath>
#include "constants.h"


// global variables

float x_lower = -2; //lower limit 
float x_higher = 3; //highest limit of x
int x_spaces = 100; // number of spaces between x_lower and x_higher

//for the discrete points
float delta_x = (x_higher-x_lower)/x_spaces ;
float delta_t = 0.00005; //seconds




using namespace std;

int main(int argc, char **argv){
	float x_values [x_spaces+1];
	float u_values [x_spaces+1]; //n+1
	float u_values_old [x_spaces+1]; //n
	float pred_values [x_spaces+1]; //n+1
	double error = 1;
	double viscous_term;

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = delta(x_values[i],-2) - delta(x_values[i],0);
	   pred_values[i] = delta(x_values[i],-2) - delta(x_values[i],0);

	}

	int loop = 1000;
	//while (error*delta_t*delta_x >= 0.00000000000000001){
	double r = meu*delta_t/pow(delta_x,2);
	while (loop>900){

		// initial predictor loop
		for (int j=0;j<=x_spaces;j++){
			
         if (j-1 < 0){
				viscous_term = r*(u_values_old[j+1] -2*u_values_old[j] + u0);
				pred_values[j] = u_values_old[j]- delta_t/(2*delta_x)*(pow(u_values_old[j+1],2)/2 - pow(u0,2)/2 ) + viscous_term;
         } else if (j+1 <= x_spaces){
				viscous_term = r*(0 -2*u_values_old[j] + u_values_old[j-1]);
				pred_values[j] = u_values_old[j]- delta_t/(2*delta_x)*(0 - pow(u_values_old[j-1],2)/2) + viscous_term;
         } else {
				viscous_term = r*(u_values_old[j+1] -2*u_values_old[j] + u_values_old[j-1]);
				pred_values[j] = u_values_old[j]- delta_t/(2*delta_x)*(pow(u_values_old[j+1],2)/2 - pow(u_values_old[j-1],2)/2) + viscous_term;
			}

			// setting up initial conditions
			if (x_values[j] <= 0){
				pred_values[j] = u0;	
			}
			if (x_values[j] >= L){
				pred_values[j] = 0;	
			}
		}

		// the actual loop
		for (int j=0;j<=x_spaces;j++){
	
         if (j-1 < 0){
				viscous_term = r*(u_values_old[j+1] -2*u_values_old[j] + u0);
				u_values[j] = u_values_old[j]- delta_t/(2*delta_x)*(pow(pred_values[j+1],2)/2 - pow(u0,2)/2 ) + viscous_term;
         } else if (j+1 <= x_spaces){
				viscous_term = r*(0 -2*u_values_old[j] + u_values_old[j-1]);
				u_values[j] = u_values_old[j]- delta_t/(2*delta_x)*(0 - pow(pred_values[j-1],2)/2) + viscous_term;
         } else {
				viscous_term = r*(u_values_old[j+1] -2*u_values_old[j] + u_values_old[j-1]);
				u_values[j] = u_values_old[j]- delta_t/(2*delta_x)*(pow(pred_values[j+1],2)/2 - pow(pred_values[j-1],2)/2) + viscous_term;
			}

			// setting up initial conditions
			if (x_values[j] <= 0){
				u_values[j] = u0;
			}
			if (x_values[j] >= L){
				u_values[j] = 0;
			}

		// setting the new speeds to old speeds
		error = 0;
		for (int i=0; i<=x_spaces;i++){
			error = error + abs(u_values[i] - u_values_old[i]);
		   u_values_old[i] = u_values[i];
		}
		loop = loop -1;
		cout << "The error for the system is: " << error << endl << ",";

	}

		//printing out the values
			for (int j=0; j<=x_spaces;j++){
				if (j==0){
				   cout << "X Explicit Value Start" << "," << x_values[j] << ",";
				}else if (j==x_spaces){
				   cout << x_values[j] << "," << "X Explicit Value End" << ",";
				}else{
				   cout << x_values[j] << ",";
				}
			} 

			for (int k=0; k<=x_spaces;k++){
				if (k==0){
				   cout << "Y Explicit Value Start" << "," << u_values_old[k] << ",";
				}else if (k==x_spaces){
				   cout << u_values[k] << "," << "Y Explicit Value End" << ","<< endl;
				}else{
				   cout << u_values[k] << ",";
				}
		
			}

	}
	return 0;
}
