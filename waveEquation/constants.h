#ifndef CONSTANTS_H
#define CONSTANTS_H
 
int delta(float x, float a); // function prototype for add.h 
float func(float x);

extern float c; //wave speed in m/s
extern float x_lower; //lower limit 
extern float x_higher; //highest limit of x
extern int x_spaces ; // number of spaces between x_lower and x_higher
extern float v_Neumann;
extern float delta_x ;
extern float delta_t;

#endif

