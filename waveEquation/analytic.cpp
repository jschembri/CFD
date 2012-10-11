#include <iostream>
#include <string>
#include <cstdlib> 
#include "constants.h"


using namespace std;


int main(int argc, char **argv){

   double t = atof(argv[1]);
   float x_values [x_spaces+1];
   float y_values [x_spaces+1];


   for (int i=0; i<=x_spaces;i++){
      x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
      y_values[i] = func(x_values[i]-c*t);
   }

   for (int j=0; j<=x_spaces;j++){
      if (j==0){
         cout << "X Analytical Value Start" << "," << x_values[j] << ",";
      }else if (j==x_spaces){
         cout << x_values[j] << "," << "X Analytical Value End" << ",";
      }else{
         cout << x_values[j] << ",";
      }
   
   } 

   for (int k=0; k<=x_spaces;k++){
      if (k==0){
         cout << "Y Analytical Value Start" << "," << y_values[k] << ",";
      }else if (k==x_spaces){
         cout << y_values[k] << "," << "Y Analytical Value End" << ",";
      }else{
         cout << y_values[k] << ",";
      }
   
   } 
   return 0; 


}

