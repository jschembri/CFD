// This file sets all the constants of the heat equation.  We assume a two-dimensional rectangle with constant temperature sides.  The rectangle is originally heated up to a temperature
#include <math.h>


float T0 = 20; // degrees C
int inf = 20;
float alpha = 1;
const double PI = 3.141592;
float a = 1;
float b = 1;

int delta(float x, float a){
   if (x >= a){
      return 1;
   }
   else {
      return 0;
   }   

}

float analytical_heat_solution(float x, float y, float t){
using namespace std;

	float sum = 0;
	float v_of_n;
	float u_of_m;
	float lamda;
	float A;

	for (int n=1;n<=inf;n++){
		for(int m=1;m<=inf;m++){

			u_of_m = m*PI/a;
			v_of_n = n*PI/b;
			lamda = alpha * pow(pow(u_of_m,2)+pow(v_of_n,2),0.5);

			A = 4*T0/(n*m*pow(PI,2))*(1+pow((-1),(m+1)))*(1+pow((-1),(n+1)));
			sum += A * sin(u_of_m*x)*sin(v_of_n*y)*exp(-pow(lamda,2)*t);

		}
		
	}

	return sum;

}





