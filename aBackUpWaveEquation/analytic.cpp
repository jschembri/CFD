#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

// global variables
float c = 1; //wave speed in m/s
// float t = 1; //time in seconds

float x_lower = -1; //lower limit 
float x_higher = 7; //highest limit of x
int x_spaces = 1000; // number of spaces between x_lower and x_higher

//for the discrete points
float v_Neumann = 0.5;
float delta_x = (x_higher-x_lower)/x_spaces ;
float delta_t = v_Neumann * delta_x / c;





int delta(float x, float a){
   if (x >= a){
      return 1;
   }
   else {
      return 0;
   }   

}

float func(float x){
   // for the first test we check the unit step
   return (delta(x,0) - delta(x,1)); 
}

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

// The next section deals with the euler explicit method

   float time = 0;

   float x_ee_values [x_spaces+1];
   float u_old_values [x_spaces+1];  
   float u_values [x_spaces+1];  
   float u_new_values [x_spaces+1];


   while (time <= t) {

      for (int i=0; i<=x_spaces;i++){
         x_ee_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
      }
     
       
      if (time == 0 ){
         for (int i=0; i<=x_spaces;i++){
            u_old_values[i] =  func(x_ee_values[i]); 
         }
      }

      for (int i=0; i<=x_spaces;i++){
         if (i==0){
            u_new_values[i] = 0;   
         }else{
            u_new_values[i] = u_old_values[i-1];
         }
      }
      
      for (int i=0; i<=x_spaces;i++){
         u_values[i] = u_old_values[i];
         u_old_values[i] = u_new_values[i];
      }
   

      time = time + delta_t;
         

   }

   for (int j=0; j<=x_spaces;j++){
      if (j==0){
         cout << "X Euler Value Start" << "," << x_ee_values[j] << ",";
      }else if (j==x_spaces){
         cout << x_ee_values[j] << "," << "X Euler Value End" << ",";
      }else{
         cout << x_ee_values[j] << ",";
      }

   } 

   for (int k=0; k<=x_spaces;k++){
      if (k==0){
         cout << "Y Euler Value Start" << "," << u_values[k] << ",";
      }else if (k==x_spaces){
         cout << u_values[k] << "," << "Y Euler Value End" << ","<< endl;
      }else{
         cout << u_values[k] << ",";
      }

   } 





   return 0; 


}

