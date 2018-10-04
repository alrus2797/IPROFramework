

#include "GPS.h"

using namespace std;


int maino(){
    Point3D a(0,1,0);
    Point3D b(0,2,0);
    auto c = a-b;
    imp(c);
    cout<<"Modulo"<<getVectorModule(c)<<endl;
    Model modelo;
    auto d = make_tuple(1,2,3);
    auto e = make_tuple(3,4,1);
    auto res = modelo.getDiff(d,e);
    cout << res.first.first <<","<< res.first.second <<" -- "<< res.second.first <<","<< res.second.second<<endl;
}

int main(){
    GPS gps("animales.pro");
    gps.getAllGPS();
}

int maini()
{
    Model modelo;
    modelo.ReadOff("animales/cat0.off");
    //modelo.ReadOff("animales/victoria25.off");
    //int pru;
    //cin>>pru;
    //modelo.PrintOFF();
    modelo.SetAngles();
    //cout<<"Done"<<endl;
    //modelo.showWeights();
    modelo.setOLBValues();
    //modelo.showOLB();
    modelo.setEigen(30);
    cout<<"------"<<endl;
    //modelo.showEigen(); 

    modelo.getGPS(30,true);
    
    //modelo.showOLB();
    //modelo.showWeights();

    // eucVector u={5,6,0};
    // eucVector v={-1,4,0};

    //cout<<"Mo: "<<getVectorModule(u)<<endl;

    // double numerador=0,denominador,res;
    // for(int i = 0; i < 3; i++)
    // {
    //     numerador += u[i]*v[i];
    // }
    // denominador = getVectorModule(u)*getVectorModule(v);

    // res = numerador/denominador;






    

    //modelo.PrintOFF();
    // Point3D a(-1,2,0);
    // Point3D b(4,5,0);
    
    // showVector(b-a);


}





