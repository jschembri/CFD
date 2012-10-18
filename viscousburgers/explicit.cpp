#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include <cmath>
#include "constants.h"


// global variables


using namespace std;

int main(int argc, char **argv){
	double x_values [x_spaces+1];
	double u_values [x_spaces+1]; //n+1
	double u_values_old [x_spaces+1]; //n
	double pred_values [x_spaces+1]; //n+1
	double error = 1;
	double viscous_term;

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = initial_conditions(x_values[i]);
	   u_values[i] = initial_conditions(x_values[i]);
	   pred_values[i] = initial_conditions(x_values[i]);

	}

	int loop = 0;
	while (loop < 100){

		// initial predictor loop
		for (int j=0;j<=x_spaces;j++){
			
         if (j == 0){
				viscous_term = r*(u_values_old[j+1] -2.0*u_values_old[j] + u0);
				pred_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(pow(u_values_old[j+1],2.0)/2.0 - pow(u0,2.0)/2.0 ) + viscous_term;
         } else if (j+1 <= x_spaces){
				viscous_term = r*(0.0 -2.0*u_values_old[j] + u_values_old[j-1]);
				pred_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(0 - pow(u_values_old[j-1],2.0)/2.0) + viscous_term;
         } else {
				viscous_term = r*(u_values_old[j+1] -2.0*u_values_old[j] + u_values_old[j-1]);
				pred_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(pow(u_values_old[j+1],2.0)/2.0 - pow(u_values_old[j-1],2.0)/2.0) + viscous_term;
			}

			// setting up initial conditions
			if (x_values[j] <= 0.0){
				pred_values[j] = u0;	
			}
			if (x_values[j] >= L){
				pred_values[j] = 0.0;	
			}
		}

		// the actual loop
		for (int j=0;j<=x_spaces;j++){
	
         if (j-1 < 0){
				viscous_term = r*(u_values_old[j+1] -2.0*u_values_old[j] + u0);
				u_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(pow(pred_values[j+1],2.0)/2 - pow(u0,2.0)/2 ) + viscous_term;
         } else if (j+1 <= x_spaces){
				viscous_term = r*(0.0 -2.0*u_values_old[j] + u_values_old[j-1]);
				u_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(0 - pow(pred_values[j-1],2.0)/2.0) + viscous_term;
         } else {
				viscous_term = r*(u_values_old[j+1] -2.0*u_values_old[j] + u_values_old[j-1]);
				u_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(pow(pred_values[j+1],2.0)/2 - pow(pred_values[j-1],2.0)/2.0) + viscous_term;
			}

			// setting up initial conditions
			if (x_values[j] <= 0.0){
				u_values[j] = u0;
			}
			if (x_values[j] >= L){
				u_values[j] = 0;
			}
		}

		// setting the new speeds to old speeds
		error = 0;
		for (int i=0; i<=x_spaces;i++){
			error = error + abs(u_values[i] - u_values_old[i]);
			if (x_values[i] <= 0.0){
				u_values[i] = u0;
			}
			if (x_values[i] >= L){
				u_values[i] = 0.0;
			}
		   u_values_old[i] = u_values[i];
		}


		loop += 1;
	}
		//printing out the values
	printarray(x_values,x_spaces+1,"X Explicit Value");
	printarray(u_values,x_spaces+1,"Y Explicit Value");
	return 0;
}
