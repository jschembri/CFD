// This file sets all the constants of the heat equation.  We assume a two-dimensional rectangle with constant temperature sides.  The rectangle is originally heated up to a temperature
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;


// global variables
float c = 1; //wave speed in m/s
float x_lower = -1; //lower limit 
float x_higher = 7; //highest limit of x
int x_spaces = 300; // number of spaces between x_lower and x_higher
float v_Neumann = 0.75;
float delta_x = (x_higher-x_lower)/x_spaces ;
float delta_t = v_Neumann * delta_x / c;
float PI = 3.14159265;

int delta(float x, float a){
   if (x >= a){
      return 1;
   }
   else {
      return 0;
   }   

}

//A Box
float func(float x){
   // for the first test we check the unit step
   return (delta(x,0) - delta(x,1)); 
}

//Unit Step
//float func(float x){
//   // for the first test we check the unit step
//   return (delta(x,1)); 
//}

//Sine wave
//float func(float x){
//   // for the first test we check the unit step
//   return (delta(x,0) - delta(x,PI))*cos(x-PI/2); 
//}

//Triangular wave
//float func(float x){
//   // for the first test we check the unit step
//   return (delta(x,0) - delta(x,0.5))*x+(delta(x,0.5) - delta(x,1))*(-x+1); 
//}




