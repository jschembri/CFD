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
	double F, FplusOne, PredF, PredFminusOne;

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = initial_conditions(x_values[i]);
	   pred_values[i] = initial_conditions(x_values[i]);

	}

	int loop = 0;
	while (loop < 10000){
		//cout << "It ran!" <<endl;
		// initial predictor loop
		for (int i=1;i<=x_spaces-1;i++){
			//F = pow(u_values_old[i],2)/2.0;
			//FplusOne = pow(u_values_old[i+1],2)/2.0;
			F = u_values_old[i];
			FplusOne = u_values_old[i+1];
			pred_values[i] = u_values_old[i] - delta_t/delta_x*(FplusOne-F)+r*( u_values_old[i+1]-2.0*u_values_old[i]+u_values_old[i-1]);
       }
		for (int i=1;i<=x_spaces-1;i++){
			//PredFminusOne=pow(pred_values[i-1],2)/2;
			//PredF=pow(pred_values[i],2)/2;
			PredFminusOne=pred_values[i-1];
			PredF=pred_values[i];
			u_values[i] = 0.5*(u_values_old[i]+pred_values[i]-delta_t/delta_x*(PredF-PredFminusOne)+r*(pred_values[i+1])-2.0*pred_values[i]+pred_values[i-1] );
		}
	
		for (int i=0;i<=x_spaces;i++){
			if (x_values[i] <= 0){
				u_values[i] = u0;
				pred_values[i] = u0;
				u_values_old[i]=u0;
				//cout << "Less than 0" << endl;
			}
			if (x_values[i] >= L){
				u_values[i] = 0;
				pred_values[i] = 0;
				u_values_old[i]=0;
			//	cout << "More than 1" << endl;
			}

			u_values_old[i] = u_values[i];
		}

		


	loop += 1;
	}
		//printing out the values
	printarray(x_values,x_spaces+1,"X Mac");
	printarray(u_values_old,x_spaces+1,"Y Mac");

	//cout << "r : " << r << endl;
	//cout << "v : " << c*delta_t/delta_x << endl;
	return 0;
}
