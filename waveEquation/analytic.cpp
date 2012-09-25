#include <iostream>
using namespace std;

int delta(int x, int a){
   if (x >= a){
      return 1;
   }
   else {
      return 0;
   }   

}

int main(){
   int i;
   int a = 2;
   int x_value[] = {0,1,2,3,4,5,6,7,8,9,10};
   int y_value[11];

   for (i=0;i<=10;i++){
      if (i==0){
         cout << "X Value Start" << "," << x_value[i] << ",";
      }else if (i==10){
         cout << x_value[i] << "," << "X Value End" << ",";
      }else{
         cout << x_value[i] << ",";
      }
   
   } 




   for (i=0;i<=10;i++){
      y_value[i] = delta(x_value[i],0) - delta(x_value[i],2);

      if (i==0){
         cout << "Y Value Start" << "," << y_value[i] << ",";
      }else if (i==10){
         cout << y_value[i] << "," << "Y Value End";
      }else{
         cout << y_value[i] << ",";
      }
   
   }   


   return 0; 


}

