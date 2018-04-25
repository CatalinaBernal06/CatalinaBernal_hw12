#include <iostream>
#include <cmath>
#include <stdlib.h>

double valor_y0 (double x);

int main(){
  float C = 1.0;
  double x = -2;
  double delta_t = 0.001;
  int N_t = 700/delta_t ;
  double delta_x = 0.01;
  int N_x = 4/delta_x +1;
  
  double *y_past = new double[N_x];
  double *y0 = new double[N_x];
  double *snap2 = new double[N_x];
  double *snap3 = new double[N_x];
  double *snap4 = new double[N_x];
  double *snap5 = new double[N_x];

 

  for(int i = 0; i<N_x; i++){
    x = i*delta_x;
    y_past[i] = valor_y0(x);
    y0[i] = valor_y0(x);
    snap2[i] = 0;
     snap3[i] = 0;
      snap4[i] = 0;
       snap5[i] = 0;
       
    
  }

  double t = 0.0;
  while(t<= N_t/4){
    for(int i = 1; i<N_x-1 ; i++){
      snap2[i] = y_past[i] - C*(delta_t/delta_x)*(y_past[i] - y_past[i-1]) ;
    }

   for(int i = 1; i <N_x - 1 ; i++){
     y_past[i] = snap2[i];
     t += delta_t;
   } 
  }

  while(t<= N_t/2){
    for(int i = 1; i<N_x-1 ; i++){
      snap3[i] = y_past[i] - C*(delta_t/delta_x)*(y_past[i] - y_past[i-1]) ;
    }

   for(int i = 1; i <N_x - 1 ; i++){
     y_past[i] = snap3[i];
     t += delta_t;
   } 
  }

  while(t<= 3*N_t/4){
    for(int i = 1; i<N_x-1 ; i++){
      snap4[i] = y_past[i] - C*(delta_t/delta_x)*(y_past[i] - y_past[i-1]) ;
    }

   for(int i = 1; i <N_x - 1 ; i++){
     y_past[i] = snap4[i];
     t += delta_t;
   } 
  }

  while(t<= N_t){
    for(int i = 1; i<N_x-1 ; i++){
      snap5[i] = y_past[i] - C*(delta_t/delta_x)*(y_past[i] - y_past[i-1]) ;
    }

   for(int i = 1; i <N_x - 1 ; i++){
     y_past[i] = snap5[i];
     t += delta_t;
   } 
  }

  x = -2;
  
  for(int i = 0; i<N_x; i++){
    std::cout << x << " " << y0[i] << " " << snap2[i] << " " << snap3[i] << " " << snap4[i] << " "  << snap5[i] << std::endl;
    x += delta_x;
  }
  
}


double valor_y0(double x){
  if(abs(x)<0.5){
    return 0.5;
  }
  else{
    return 0;
  }
}
