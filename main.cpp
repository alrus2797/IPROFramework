

#include "Model.h"

using namespace std;




int main()
{
    Model modelo;
    modelo.ReadOff("test.off");
    modelo.SetAngles();

    modelo.showWeights();

    //modelo.PrintOFF();
    // Point3D a(-1,2,0);
    // Point3D b(4,5,0);
    
    // showVector(b-a);


}





