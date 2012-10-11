#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <cstdlib> 
#include "constants.h"

using namespace std;
using namespace Eigen;

int main(int argc, char **argv){

   double t = atof(argv[1]);
   float x_values [x_spaces+1];
   float y_values [x_spaces+1];
   float u_old[x_spaces+1];


   for (int i=0; i<=x_spaces;i++){
      x_values[i] = x_lower + (x_higher-x_lower)/x_spaces * i;
      y_values[i] = func(x_values[i]-c*t);
   }

   MatrixXf A = MatrixXf::Zero(x_spaces+1,x_spaces+1);
   VectorXf b(x_spaces+1,1);
   VectorXf u_new(x_spaces+1,1);

// The next section deals with the euler explicit method
   float time = 0;
   while (time <= t) {

      for (int i=0;i<=x_spaces;i++){
         if (i-1 >= 0){
            A(i-1,i) = v_Neumann /2;
         }

         if (i+1 <= x_spaces){
            A(i+1,i) = -v_Neumann /2; 
         }

         A(i,i) = 1;

         if (time ==0 ){
            b(i) = func(x_values[i]);
         /*}else if (i == x_spaces) {
            b(i) = u_old[i] - v_Neumann /2;
         }else if (i == 0) {
            b(i) = u_old[i] + v_Neumann /2; */
         }else{
            b(i) = u_old[i];
         }
      }
      //b(x_spaces) = u_old[x_spaces] - v_Neumann /2*u_old[x_spaces]; 
      u_new = A.colPivHouseholderQr().solve(b);

   time = time + delta_t;
   for (int i=0;i<=x_spaces;i++){
      u_old[i] = u_new(i);
   }



      
   }

      
   for (int k=0; k<=x_spaces;k++){
      if (k==0){
         cout << "Y Implicit Value Start" << "," << u_new(k) << ",";
      }else if (k==x_spaces){
         cout << u_new(k) << "," << "Y Implicit Value End" << ",";
      }else{
         cout << u_new(k) << ",";
      }
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


//   cout << "Here is the matrix A:\n" << A << endl;
//   cout << "Here is the vector b:\n" << b << endl;


   return 0; 


}



