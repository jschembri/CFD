// This file sets all the constants of the heat equation.  We assume a two-dimensional rectangle with constant temperature sides.  The rectangle is originally heated up to a temperature

float c = 1; //wave speed in m/s
float x_lower = 0; //lower limit 
float x_higher = 5; //highest limit of x
int x_spaces = 100; // number of spaces between x_lower and x_higher
float v_Neumann = 0.5;
float delta_x = (x_higher-x_lower)/x_spaces ;
float delta_t = v_Neumann * delta_x / c;
float PI = 3.14159265;


// Convergence criteria
//float delta_t = 0.1; //seconds
float omega = 0.5;



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
   return delta(x,0); 
}



