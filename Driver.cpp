#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;
double n = 0.01;

int apply(double* p, double in1, double in2){
   int temp = (in1 * p[0]) + (in2*p[1]) -p[2];
   int t = 0;
   if(temp>0){
      t= 1;
   }
   
   return t;
}
void train(double* p, double in1, double in2, int out){
//threshold is the weight w0 with constant input w0.
   int temp = (in1 * p[0]) + (in2*p[1]) -p[2];
   int t = 0;
   if(temp>0){
      t= 1;
   }
   p[0] = p[0]+ (n* (t- out)* in1);
   p[1] = p[1]+ (n* (t- out)* in2);
   p[2] = p[2] + (n*(t-out)); //threshold, input is kept at 1
   
   
   
   
      
}

void train(double* p, string filename){

   ifstream myfile(filename.c_str());
  
   vector<double> v;
   string line;
   double a, b;
   int   out;
   
   if (myfile.is_open()) {
      while(getline(myfile, line)){
         stringstream ss(line);
         ss>> a>>b>>out;
         v.push_back(a);v.push_back(b);v.push_back(out);
      }
   }
   myfile.close();
   
   //perceptron training rule
   int iterations= 100;
   while(iterations>=0){
      for(int i = 0; i< (v.size())/3 ; i++){
      
         train(p, v.at(i*3), v.at((i*3) + 1), v.at((i*3) +2));
         
      }
      iterations--;
   }

   
}
int main(){
  
   
   
  //each array represents a perceptron with elements weight1, weight2 and bias respectively
   double p1[3] = {1.0,1.0, 1.0};
   double p2[3] = {1.0,1.0,1.0}; 
   double p3[3] = {1.0,1.0,1.0};

    
   train(p1, "or.txt");
   
   
   train(p2, "nand.txt");
   
   
   train(p3, "and.txt");
   
 
    
   
      
   cout<<"The perceptron p1 has weights "<< p1[0] <<" , " <<p1[1] << " and bias " << p1[2]<<endl;
   cout<<"The perceptron p2 has weights "<< p2[0] <<" , " <<p2[1] << " and bias " << p2[2]<<endl;
   cout<<"The perceptron p3 has weights "<< p3[0] <<" , " <<p3[1] << " and bias " << p3[2]<<endl;
   
   vector<double> test;
   test.push_back(1.0); test.push_back(1.0);test.push_back(0.0);
   test.push_back(1.0); test.push_back(0.0);test.push_back(1.0);
   test.push_back(0.0); test.push_back(1.0);test.push_back(1.0);
   test.push_back(0.0); test.push_back(0.0);test.push_back(0.0);
   for(int i =0 ; i< test.size()/3; i++){
      int or_output = apply(p1,test[3*i], test[(3*i)+1]);  
       int nand_output = apply(p2,test[3*i], test[(3*i)+1]); 
      int xor_output = apply(p3,or_output, nand_output);
       
      if(xor_output ==(int)test.at(2)){
         cout<<"Correct!"<<endl;
      }
      else{
         cout<<"Incorrect!"<<endl;
      }  
   }
   
   
   
}

