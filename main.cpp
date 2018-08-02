

#include "Model.h"

using namespace std;




int main()
{
    Model modelo;
    modelo.ReadOff("test.off");
    modelo.SetAngles();

    modelo.showWeights();

    eucVector u={5,6,0};
    eucVector v={-1,4,0};

    //cout<<"Mo: "<<getVectorModule(u)<<endl;

    double numerador=0,denominador,res;
    for(int i = 0; i < 3; i++)
    {
        numerador += u[i]*v[i];
    }
    denominador = getVectorModule(u)*getVectorModule(v);

    res = numerador/denominador;



    

    //modelo.PrintOFF();
    // Point3D a(-1,2,0);
    // Point3D b(4,5,0);
    
    // showVector(b-a);


}





