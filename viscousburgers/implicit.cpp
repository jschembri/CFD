#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <cstdlib> 
#include "constants.h"

using namespace std;
using namespace Eigen;



int main(int argc, char **argv){

   double t = atof(argv[1]);
   float time = 0;
   float x_values [x_spaces+1];
   float u_old[x_spaces+1];

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_old[i] = initial_conditions(x_values[i]);
	}


   MatrixXf A = MatrixXf::Zero(x_spaces+1,x_spaces+1);
   VectorXf b(x_spaces+1,1);
   VectorXf u_values(x_spaces+1,1);

// The next section deals with the euler explicit method

   while (time <= t) {

      for (int i=0;i<=x_spaces;i++){
         if (i-1 >= 0){
            A(i,i-1) = -u_old[i-1]/(4.0*delta_x)-1.0*meu/(2*pow(delta_x,2));
         }

         if (i+1 <= x_spaces){
            A(i,i+1) = u_old[i+1]/(4.0*delta_x)-1.0*meu/(2*pow(delta_x,2));
         }
         A(i,i) = 1.0/delta_t+2.0*meu/pow(delta_x,2);


         if (i-1 < 0){
         	b(i) = 1;
			}else if (i+1>x_spaces){
				b(i) = 1;
			}else{
         	b(i) = u_old[i] -1.0/(2.0*delta_x)*(pow(u_old[i+1],2)/2.0-pow(u_old[i-1],2.0))+1.0/(4*delta_x)*(pow(u_old[i+1],2)+pow(u_old[i-1],2))+meu/(2.0*pow(delta_x,2))*(u_old[i+1]-u_old[i]+u_old[i-1]);
			}
     
      }
      //b(x_spaces) = u_old[x_spaces] - v_Neumann /2*u_old[x_spaces]; 
      u_values = A.colPivHouseholderQr().solve(b);

		time = time + delta_t;

		if (time >= t){
			break;
		}
		for (int i=0;i<=x_spaces;i++){
		   u_old[i] = u_values(i);
		}

  }    

 
 
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;



   return 0; 


}



