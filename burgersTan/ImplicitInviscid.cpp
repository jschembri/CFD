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
   //float u_values [x_spaces+1];
   float u_old[x_spaces+1];
	float correction_factor;

	for (int i=0; i<=x_spaces;i++){
	   x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
	   u_old[i] = func(x_values[i]);
	}


   MatrixXf A = MatrixXf::Zero(x_spaces+1,x_spaces+1);
   VectorXf b(x_spaces+1,1);
   VectorXf u_values(x_spaces+1,1);

// The next section deals with the euler explicit method

   while (time <= t) {

      for (int i=0;i<=x_spaces;i++){
         if (i-1 >= 0){
            A(i,i-1) = -delta_t/(4*delta_x)*(u_old[i-1]);
         }

         if (i+1 <= x_spaces){
            A(i,i+1) = delta_t/(4*delta_x)*(u_old[i+1]); 
         }
         A(i,i) = 1;

			if (i-2<0){
				correction_factor = -omega/8*(u_old[i+2] -4*u_old[i+1]+6*u_old[i]);
			}else if (i-1<0){
				correction_factor = -omega/8*(u_old[i+2] -4*u_old[i+1]+6*u_old[i]-4*u_old[i-1]);
			}else if (i+1>x_spaces){
				correction_factor = -omega/8*(-4*u_old[i+1]+6*u_old[i]-4*u_old[i-1]+u_old[i-2]);
			}else if (i+2>x_spaces){
				correction_factor = -omega/8*(6*u_old[i]-4*u_old[i-1]+u_old[i-2]);
			}else{
				correction_factor = -omega/8*(u_old[i+2] -4*u_old[i+1]+6*u_old[i]-4*u_old[i-1]+u_old[i-2]);
			}


         if (i-1 < 0){
         	b(i) = -delta_t/(2*delta_x)*(pow(u_old[i+1],2)/2-pow(ustart,2)/2)-delta_t/(4*delta_x)*pow(ustart,2) + u_old[i]+delta_t/(4*delta_x)*pow(u_old[i+1],2)+correction_factor;
			}else if (i+1>x_spaces){
				b(i) = -delta_t/(2*delta_x)*(pow(uend,2)/2-pow(u_old[i-1],2)/2)-delta_t/(4*delta_x)*pow(u_old[i-1],2) + u_old[i]+delta_t/(4*delta_x)*pow(uend,2)+correction_factor;
			}else{
         	b(i) = -delta_t/(2*delta_x)*(pow(u_old[i+1],2)/2-pow(u_old[i-1],2)/2)-delta_t/(4*delta_x)*pow(u_old[i-1],2) + u_old[i]+delta_t/(4*delta_x)*pow(u_old[i+1],2)+correction_factor;
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
		u_old[0]=ustart;
		u_values[0] = ustart;
		u_old[x_spaces]=uend;
		u_old[x_spaces]=uend;

  }    

		for (int j=0; j<=x_spaces;j++){
		   if (j==0){
		      cout << "X Implicit Value Start" << "," << x_values[j] << ",";
		   }else if (j==x_spaces){
		      cout << x_values[j] << "," << "X Implicit Value End" << ",";
		   }else{
		      cout << x_values[j] << ",";
		   }
		
		} 

		for (int k=0; k<=x_spaces;k++){
		   if (k==0){
		      cout << "Y Implicit Value Start" << "," << u_old[k] << ",";
		   }else if (k==x_spaces){
		      cout << u_old[k] << "," << "Y Implicit Value End"<<","<<endl;
		   }else{
		      cout << u_old[k] << ",";
		   }
	  
}

 
 



/*
   cout << "Here is the matrix A:\n" << A << endl;
   cout << "Here is the vector b:\n" << b << endl;
   cout << "A(0,1)"<<endl;
   cout << A(0,1)<< endl;
*/

   return 0; 


}



