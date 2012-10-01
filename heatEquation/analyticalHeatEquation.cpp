// This is an analytical program to calculate the analytical solution to the two-dimensional heat equation

#include <iostream>
#include <string>
#include <cstdlib> 
#include "constants.h"

float solution;
using namespace std;

int main(int argc, char **argv){
	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double t = atof(argv[3]);	

	solution = analytical_heat_solution(x,y,t);
	cout << solution;
	return 0;

}

