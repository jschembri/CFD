// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation

#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
#include "constants.h"

using namespace std;

void printarray (float arg[], int length, string input) {
  for (int i=0; i<length; i++)
      if (i==0){
         cout << input <<" Start" << "," << arg[i] << ",";
      }else if (i==length-1){
         cout << arg[i] << "," << input <<" End" << ",";
      }else{
         cout << arg[i] << ",";
      }
}


using namespace std;

int main(int argc, char **argv){
	double x_values [x_spaces+1];
	double y_values [x_spaces+1]; //n+1
   double time = atof(argv[1]);


	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
		if (x_values[i] <= 0 ){
			y_values[i] =  0;
		} else if (x_values[i] >= time){
			y_values[i] =  1; 
		} else {
			y_values[i] =  x_values[i] / time;

		}
	}

	printarray(x_values,x_spaces+1,"X Value");
	printarray(y_values,x_spaces+1,"Y Value");




	
	return 0;
}
