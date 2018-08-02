#include <vector>
using namespace std;

typedef vector<double> eucVector;


class Point3D
{
    public:

       double x;
       double y;
       double z;


        Point3D(double x, double y, double z){
            this->x=x;
            this->y=y;
            this->z=z;
        }

        
        bool operator== (Point3D & p){
            if (x==p.x && y==p.y && z==p.z)
                return true;
            return false;
        }
        bool operator= (Point3D & p)
        {
            this->x=p.x;
            this->y=p.y;
            this->z=p.z;
        }

        eucVector operator- (Point3D & p)
        {
            eucVector res;
            res.push_back(x-p.x);
            res.push_back(y-p.y);
            res.push_back(z-p.z);
            return res;
        }

        friend ostream& operator << (ostream &o,const Point3D &p);

};

ostream& operator << (ostream &o,const Point3D &p)
{
    o << p.x << ", " << p.y << ", "<<p.z;
    return o;
}

void showVector(eucVector v,string message="vector")
{
    cout<<message<<": ( ";
    for(auto i: v)
    {
        cout<<i<<" ";
    }
    cout<<")"<<endl;
}

