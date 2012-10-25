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
	double viscous_term;
   double endtime = atof(argv[1]);
	double time=0;

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = initial_conditions(x_values[i]);
	   u_values[i] = initial_conditions(x_values[i]);
	   pred_values[i] = initial_conditions(x_values[i]);

	}

	//cout << "r: " << r << endl;
	//cout << "delta_t: " << delta_t << endl;
	//cout << "delta_x: " << delta_x << endl;

	while (time < endtime){

		for (int j=1;j<=x_spaces-1;j++){
			viscous_term = r*(u_values_old[j+1] -2.0*u_values_old[j] + u_values_old[j-1]);
			pred_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(pow(u_values_old[j+1],2.0)/2.0 - pow(u_values_old[j-1],2.0)/2.0) + viscous_term;
		}

		// the actual loop
		for (int j=1;j<=x_spaces-1;j++){
			viscous_term = r*(u_values_old[j+1] -2.0*u_values_old[j] + u_values_old[j-1]);
			u_values[j] = u_values_old[j]- delta_t/(2.0*delta_x)*(pow(pred_values[j+1],2.0)/2 - pow(pred_values[j-1],2.0)/2.0) + viscous_term;

		}

		// setting the new speeds to old speeds
		for (int i=1; i<=x_spaces-1;i++){
		   u_values_old[i] = u_values[i];
		}


		time += delta_t;
	}
		//printing out the values
	printarray(x_values,x_spaces+1,"X Explicit Value");
	printarray(pred_values,x_spaces+1,"Predict");
	printarray(u_values,x_spaces+1,"Y Explicit Value");
	return 0;
}
