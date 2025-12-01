#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
// curva de frecuencia at
int llegadas(double r){
    int at;
    if(r<=0.2)
        at=5;
    else if(r<=0.55)
        at=10;
    else if(r<=1)
        at=15;
    return at;
}
// curva de frecuencia st
int servicio(double r){
    int st;
    if(r<=0.5)
        st=10;
    else if(r<=0.75)
        st=15;
    else if(r<=1)
        st=20;
    return st;
}

int main(){
    int simt,i=0,reloj=0,reloj1=0,sumwt=0,a,st,wt,n;
    double r;
    srand(time(0)); // semilla
    cout<<"Ingrese tiempo de simulaciÃ³n (minutos): "; cin>>simt;
    do{
        n=rand();
        r=static_cast<double>(n)/RAND_MAX;
        a=llegadas(r);
        n=rand();
        r=static_cast<double>(n)/RAND_MAX;
        st=servicio(r);
        reloj+=a;
        if(reloj>=reloj1){
            reloj1=reloj+st;
        }
        else{
            wt=reloj1-reloj;
            sumwt+=wt;
            reloj1=reloj+wt+st;
        }
        i=i+1;
    }while(reloj<simt);
    float tp=sumwt/i;
    cout<<"\nEl tiempo promedio de espera es: "<<tp;
    return 0;
}