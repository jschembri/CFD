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
	double t = 0;
   double time = atof(argv[1]);
	double FplusHalf;
	double FminusHalf;
	double F;
	double AplusHalf;
	double AminusHalf;

	//cout << "The time is: " << time << endl;
		// setting initial parameters
	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_values_old[i] = func(x_values[i]);
	}

	//cout << "Data" << endl;
	//cout << "Delta T is: "<< delta_t <<", delta x: " << delta_x << " delt/delx: " << delta_t/delta_x << endl;
	//cout <<"Time|x_space|x_value|u_old|Fplus|Fminus|Aplus|Aminus" <<endl;
	while (t <= time+delta_t){
		u_values_old[0] = 0;
		u_values_old[x_spaces] = 1;
		u_values[0] = 0;
		u_values[x_spaces] = 1;

		// Implementin the Lax Method
		for (int i=1;i<x_spaces;i++){
			F = 0.5*pow(u_values_old[i],2);

//			if (i-1<0){
//				FplusHalf = pow(u_values_old[i+1],2)/2.0;
//				FminusHalf = 0.0;	
//				AplusHalf = (u_values_old[i]+u_values_old[i+1])/2.0; 	
//				AminusHalf = (u_values_old[i]+0)/2.0; 
//			}else if (i+1>x_spaces){
//				FplusHalf = pow(1.0,2)/2.0;
//				FminusHalf = pow(u_values_old[i-1],2)/2.0;	
//				AplusHalf = (u_values_old[i]+1.0)/2.0; 	
//				AminusHalf = (u_values_old[i]+u_values_old[i-1])/2.0;
//			}else{
				FplusHalf = 0.5*pow(u_values_old[i+1],2);
				FminusHalf = 0.5*pow(u_values_old[i-1],2);	
				AplusHalf = (u_values_old[i]+u_values_old[i+1])/2.0; 	
				AminusHalf = (u_values_old[i]+u_values_old[i-1])/2.0; 

			//}
				u_values[i] =  u_values_old[i] - delta_t/(delta_x)*(FplusHalf - FminusHalf)/2.0 + 0.5*pow(delta_t/delta_x,2)*
(AplusHalf*(FplusHalf-F) - AminusHalf*(F-FminusHalf));
			//cout <<t<<"|"<<i<<"|"<<"|"<<x_values[i]<<"|"<<u_values[i]<<"|"<<FplusHalf<<"|"<<FminusHalf<<"|"<<AplusHalf<<"|"<<AminusHalf<<endl;
		}



		// setting the new speeds to old speeds
		for (int i=0; i<=x_spaces;i++){
		   u_values_old[i] = u_values[i];
		}
		
		t += delta_t;

	}

	printarray(x_values,x_spaces+1,"X Lax-Wendroff");
	printarray(u_values,x_spaces+1,"Y Lax-Wendroff");

	return 0;
}
