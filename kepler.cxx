#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int hamiltonian(double* q,double* p,double& H);

int main(){
    
    ofstream out("symeuler2.txt");
    double q[2]; //
    double p[2]; //
    double e=0.6; //eccentricity of the ellipse
    const int tend=20*3.14;
    const double dt1=0.0005;
    const int N1= tend/dt1;
    const double dt2=0.05;
    const int N2= tend/dt2;
    double H,Hq;

    
    //initial conditions
    q[0]=1-e;
    q[1]=0;
    p[0]=0;
    p[1]=sqrt((1+e)/(1-e));
    
    
    for(int i=0;i<N2;i++){
        hamiltonian(q,p,H);
        out << i*dt2 << " " << H << " " << q[0]<< " " << q[1] << endl;
                    
                    
        Hq=1/pow((pow(q[0],2)+pow(q[1],2)),(3.0/2.0));
        p[0]=p[0]-dt2*q[0]*Hq;
        p[1]=p[1]-dt2*q[1]*Hq;
        q[0]=q[0]+dt2*p[0];
        q[1]=q[1]+dt2*p[1];
        
    }
    out.close();
    return 0;
}


int  hamiltonian(double* q,double* p,double& H){
    
    return
    H= 0.5*(pow(p[0],2)+pow(p[1],2)) - 1.0/(sqrt(pow(q[0],2)+pow(q[1],2)));
    

}