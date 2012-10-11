#include <iostream>
#include <string>
#include <cstdlib> 
#include <math.h>
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

// The next section deals with the euler explicit method

   float time = 0;

   float x_ee_values [x_spaces+1];
   float u_old_values [x_spaces+1];  
   float u_values [x_spaces+1];  
   float u_half [x_spaces+1];
   float u_two [x_spaces+1];

	double vee = v_Neumann;
	double omega = (4*pow(vee,2)+1)*(4-pow(vee,2))/5;
	//double omega = 4*vee*vee-pow(vee,4);
   while (time <= t) {
	
      for (int i=0; i<=x_spaces;i++){
         x_ee_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
      }
     
       
      if (time == 0 ){
         for (int i=0; i<=x_spaces;i++){
            u_old_values[i] =  func(x_ee_values[i]); 
         }
      }

		// first loop
      for (int i=0; i<=x_spaces;i++){
         if (i == x_spaces+1){
            u_half[i] = 0;
         }else{
            u_half[i] = 1/2*(u_old_values[i+1] + u_old_values[i]) -vee/3*(u_old_values[i+1] - u_old_values[i]);
         }
      }

		//second loop
      for (int i=0; i<=x_spaces;i++){
         if (i-1 <  0 ){
            u_two[i] = 0;
         }else{
            u_two[i] = u_old_values[i] -2*vee/3*(u_half[i] - u_half[i-1]);
         }
      }
		
		//third loop
      for (int i=0; i<=x_spaces;i++){
         if (i < 2 || i > x_spaces-2 ){
	            u_values[i] = 0;
         }else{
            u_values[i] = u_old_values[i] -vee/24*(-2*u_old_values[i+2] +7*u_old_values[i+1] -7*u_old_values[i-1]+2*u_old_values[i-2]) -3*vee/8*(u_two[i+1]-u_two[i-1])-omega/24*(u_old_values[i+2] -4*u_old_values[i+1] +6*u_old_values[i]-4*u_old_values[i-1]+u_old_values[i-2]);
         }
      }

      
      for (int i=0; i<=x_spaces;i++){
         u_old_values[i] = u_values[i];
      }
   

      time = time + delta_t;
         

   }

   for (int j=0; j<=x_spaces;j++){
      if (j==0){
         cout << "X Rusanov Value Start" << "," << x_ee_values[j] << ",";
      }else if (j==x_spaces){
         cout << x_ee_values[j] << "," << "X Rusanov Value End" << ",";
      }else{
         cout << x_ee_values[j] << ",";
      }

   } 

   for (int k=0; k<=x_spaces;k++){
      if (k==0){
         cout << "Y Rusanov Value Start" << "," << u_values[k] << ",";
      }else if (k==x_spaces){
         cout << u_values[k] << "," << "Y Rusanov Value End" << ","<< endl;
      }else{
         cout << u_values[k] << ",";
      }

   } 





   return 0; 


}

