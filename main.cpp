#include "Model.h"



int main()
{
    Model<3> modelo;
    modelo.ReadOff("0003.sampling.3.off");
    modelo.PrintOFF();
    cout<<endl;
    modelo.SetAngles();
    modelo.showWeights();

    cout<<endl;
    modelo.setOLBValues();
    modelo.showOLB();
    // PointD<2> a({-1,2});
    // PointD<2> b({3,5});
    // a=b;
    // eucVector res= (b-a);

    // cout<< res <<endl;
    //int pru;
    //cin>>pru;
    // modelo.SetAngles();
    // cout<<"Done"<<endl;
    // modelo.setOLBValues();
    // modelo.showOLB();
    

}





