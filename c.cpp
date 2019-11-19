#include <iostream>
#include <cmath>

double const D=1;
double const s=1;
int const Nx=30; // Numero de nodos en x
int const Nt=100;
float const deltax=2/Nx;
float const deltat=1/Nt;
float front=0;

void zero(int N,int Nx, float **m);
void psieneltiempo(float **m);

int main(void)
{
float psi0=0;
float psi1=0;
float psi2=0;


float xi=-1;
float xf=1;
double ti=0;
double tf=1;

float ** matriz = new float *[Nt];

for (int i =0; i < Nt; ++i){matriz[i] = new float[Nx];}
zero(Nt,Nx,matriz);
psieneltiempo(matriz);
return 0;
}

void psieneltiempo(float **m)
{
 for(int j=1; j<Nx-1; j++){
   for(int n=1;n<Nt-1;n++){
     m[n+1][j]=m[n][j]+(D*deltat/(deltax*deltax))*(m[n][j+1]-2*m[n][j]+ m[n][j-1])+deltat*s; 
    std::cout<<" "<<m[n][j]<<" ";
   }
   std::cout<<std::endl;
 }
}

void zero(int N,int Nx, float **m){
  
  for(int ii=0;ii<Nt; ii++){
     for(int ij=0;ij<Nx; ij++){
      m[ii][ij]=0;
       
     }
 
  }
  
}