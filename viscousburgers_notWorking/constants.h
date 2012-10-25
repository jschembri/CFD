#ifndef CONSTANTS_H
#define CONSTANTS_H

using namespace std;
 
int delta(float x, float a); // function prototype for add.h 
double initial_conditions(double x);
double bisection_search(double umin, double umax);
void printarray (double arg[], int length, string input);

extern double u0;
extern double L ;
extern double meu ;
extern double ReL;
extern double c;

extern double x_lower; //lower limit 
extern double x_higher; //highest limit of x
extern int x_spaces; // number of spaces between x_lower and x_higher

//for the discrete points
extern double delta_x;
extern double delta_t; //seconds

extern double ReDeltaX;
extern double r;


#endif

