

//#include "Model.h"
#include "PointD.h"

using namespace std;


int main()
{
 //   Model modelo;
//    modelo.ReadOff("test.off");
    PointD<2> a({-1,2});
    PointD<2> b({3,5});

    eucVector res= (b-a);

    cout<< res <<endl;
    //int pru;
    //cin>>pru;
    // modelo.SetAngles();
    // cout<<"Done"<<endl;
    // modelo.setOLBValues();
    // modelo.showOLB();
    

}





