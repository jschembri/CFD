// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation

#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include "constants.h"


using namespace std;

int main(int argc, char **argv){
	float x_values [x_spaces+1];
	float u_values [x_spaces+1]; //n+1
	float u_values_old [x_spaces+1]; //n
	double t = 0;
   double time = atof(argv[1]);

	//cout << "The time is: " << time << endl;
		// setting initial parameters
	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = func(x_values[i]);
	}


	while (t <= time+delta_t){



	

		// Implementin the Lax Method
		for (int j=0;j<=x_spaces;j++){
			if (j-1<0){
				u_values[j] =  (u_values_old[j+1] + ustart)/2 - delta_t/(2*delta_x)*(pow(u_values_old[j+1],2)/2 - pow(ustart,2)/2);
			}else if (j+1>x_spaces){
				u_values[j] =  (uend + u_values_old[j-1])/2 - delta_t/(2*delta_x)*(pow(uend,2)/2 - pow(u_values_old[j-1],2)/2);
			}else{
				u_values[j] =  (u_values_old[j+1] + u_values_old[j-1])/2 - delta_t/(2*delta_x)*(pow(u_values_old[j+1],2)/2 - pow(u_values_old[j-1],2)/2);
			}
		}

		//printing out the values
		//cout << "time: " <<time<<" ,t: " << t<< endl;
		if (t >= time){
			for (int j=0; j<=x_spaces;j++){
				if (j==0){
				   cout << "X Lax Value Start" << "," << x_values[j] << ",";
				}else if (j==x_spaces){
				   cout << x_values[j] << "," << "X Lax Value End" << ",";
				}else{
				   cout << x_values[j] << ",";
				}
		
		} 


			for (int k=0; k<=x_spaces;k++){
				if (k==0){
				   cout << "Y Lax Value Start" << "," << u_values_old[k] << ",";
				}else if (k==x_spaces){
				   cout << u_values_old[k] << "," << "Y Lax Value End" << ","<< endl;
				}else{
				   cout << u_values_old[k] << ",";
				}
		
			}
		}

		// setting the new speeds to old speeds
		for (int i=0; i<=x_spaces;i++){
		   u_values_old[i] = u_values[i];
		}
		
		t += delta_t;
		//cout << t << endl;
	}
	return 0;
}
