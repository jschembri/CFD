#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include "constants.h"


using namespace std;

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


int main(int argc, char **argv){
	double x_values [x_spaces+1];
	double u_values [x_spaces+1]; //n+1
	double u_values_old [x_spaces+1]; //n
	double u_pred[x_spaces+1]; //n
	double t = 0;
   double time = atof(argv[1]);


	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = func(x_values[i]);
	}
	while (t <= time+delta_t){
		u_values_old[0] = ustart;
		u_values_old[x_spaces] = uend;
		u_pred[0] = ustart;
		u_pred[x_spaces] = uend;
		u_values[0] = ustart;
		u_values[x_spaces] = uend;

		// Implementin the Lax Method
		for (int i=0;i<=x_spaces;i++){
			if (i==x_spaces){
				u_pred[i] = u_values_old[i] - delta_t/(delta_x)*(pow(uend,2)/2.0 - pow(u_values_old[i],2)/2.0);
			}else{
				u_pred[i] = u_values_old[i] - delta_t/(delta_x)*(pow(u_values_old[i+1],2)/2.0 - pow(u_values_old[i],2)/2.0);
			}
		}

		for (int i=0;i<=x_spaces;i++){
			if (i ==0){
				u_values[i] = 0.5*(u_values_old[i]+u_pred[i]-delta_t/(delta_x)*(pow(u_pred[i],2)/2.0 - pow(uend,2)/2.0));
			}else{
				u_values[i] = 0.5*(u_values_old[i]+u_pred[i]-delta_t/(delta_x)*(pow(u_pred[i],2)/2.0 - pow(u_pred[i-1],2)/2.0));
			}		
		}



		// setting the new speeds to old speeds
		for (int i=0; i<=x_spaces;i++){
		   u_values_old[i] = u_values[i];
		}
		
		t += delta_t;

	}
		u_values_old[0] = ustart;
		u_values_old[x_spaces] = uend;
		u_pred[0] = ustart;
		u_pred[x_spaces] = uend;
		u_values[0] = ustart;
		u_values[x_spaces] = uend;
	printarray(x_values,x_spaces+1,"X Mac");
	printarray(u_values,x_spaces+1,"Y Mac");

	return 0;
}
