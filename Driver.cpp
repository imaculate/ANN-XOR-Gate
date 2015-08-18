#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
double n = 0.5;

int train(double* p, double in1, double in2, int out){
   int temp = (in1 * p[0]) + (in2*p[1]) - p[2];
   int t = 0;
   if(temp>0){
      t= 1;
   }
   p[0] = p[0]+ (n* (t- out)* in1);
   p[1] = p[1]+ (n* (t- out)* in2);
   
   
   return t;
   
   
      
}
int main(){
   ifstream myfile;
   string line;
   double a, b;
   int   out;
   //inputs to hidden layers
   int h1 , h2;
   int ho1, ho2; //hidden output to be trained.
  //each array represents a perceptron with elements weight1, weight2 and threshold
   double p1[3] = {1.0,1.0, 1.0};
   double p2[3] = {1.0,1.0,1.0}; 
   double p3[3] = {1.0,1.0,1.0};
    myfile.open ("data.txt");
    
   
   if (myfile.is_open()) {
      while(getline(myfile, line)){
         stringstream ss(line);
         ss>> a>>b>>out;
         ho1=  (abs(a-1)<0.5 || a<0)?0:(b<0|| abs(b-1)<0.5)?0:1;//and output
         //ho1 = (ho1==0)?1:0;//it is a not and
         ho2 = (abs(a-1)>0.5 && a>0)?1:(b>0 && abs(b-1)>0.5)?1:0;// or output  
         int h1 = train(p1 ,a,b, ho1);
         int h2  = train(p2 ,a,b, ho2);
         train(p3, h1, h2, out);
      }
      myfile.close();
   }
   
   cout<<" The perceptron p1 has weights "<< p1[0] <<" , " <<p1[1] << " and threshold " << p1[2]<<endl;
    cout<<" The perceptron p2 has weights "<< p2[0] <<" , " <<p2[1] << " and threshold " << p2[2]<<endl;
     cout<<" The perceptron p3 has weights "<< p3[0] <<" , " <<p3[1] << " and threshold " << p3[2]<<endl;
   
   
   
   
}

