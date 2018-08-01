#include <iostream>
#include <armadillo>
#include <vector>
#include <tuple>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;
using namespace arma;

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


        // Point3D(Point3D &p) 
        // {
        //     this->x=p.x;
        //     this->y=p.y;
        //     this->z=p.z;
        // }
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

    eucVector operator - (Point3D & p)
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


vector<double> getVector(tuple<double,double,double> t1, tuple<double,double,double> t2 ){
    cout<<"f"<<endl;
    vector<double> vec;
    vector<double>p1,p2;
    double v1,v2,v3;
    tie(v1,v2,v3)=t1;
    p1={v1,v2,v3};
    tie(v1,v2,v3)=t2;
    p2={v1,v2,v3};

    for(int i = 0; i < 3; i++)
    {
        double res=p1[i]-p2[i];
        vec.push_back(res);
    }
    return vec;
    
    

    

}


class Model
{
    private:
        vector< Point3D >  m_Vertexs;
        vector< tuple<int,int,int> >  m_Faces;
        map < pair<int,int>, double>  Weights;

        int nvertices;
        int nfaces;
        int edges;
     
    public:

        pair<pair<int,int>,vector<int>> getDiff(tuple<int,int,int>& t1 , tuple<int,int,int>& t2)
        {
            int v1,v2,v3;
            tie(v1,v2,v3)=t1;
            vector<int> s1,s2;
            s1={v1,v2,v3};
            tie(v1,v2,v3)=t2;
            s2={v1,v2,v3};
            vector<int> diff,eq;

            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            for(int i = 0; i < 3; i++)
            {
                if (s1[i]!=s2[i])
                {
                    diff.push_back(s1[i]);
                    diff.push_back(s2[i]);
                }
                else{
                    eq.push_back(s1[i]);
                }
            }
            sort(diff.begin(),diff.end());
            return make_pair(make_pair(diff[0],diff[1]),eq);
        }

        void PrintOFF(){
            for(int i = 0; i < nvertices; i++)
            {
                //cout<< get<0>(m_Vertexs[i])<<" "<< get<1>(m_Vertexs[i])<<" "<< get<2>(m_Vertexs[i])<<endl;
                cout<<m_Vertexs[i]<<endl;
            }

            cout<<" "<<endl;
            for(int i = 0; i < nfaces; i++)
            {
                cout<< get<0>(m_Faces[i]) <<" "<<get<1>(m_Faces[i])<<" "<<get<2>(m_Faces[i])<<endl  ;
            }
        }
     
        void ReadOff(string  filename){
            ifstream file;
            file.open(filename);
            string line;
            file>>line;
            file>>nvertices >> nfaces >> edges;
            cout<<nvertices <<" " <<nfaces <<"  "<< edges<<endl;

            double x,y,z;

            for(int i = 0; i < nvertices; i++)
            {
                file>> x >> y >>z;
                //m_Vertexs.push_back(make_tuple(x,y,z));
                m_Vertexs.push_back(Point3D(x,y,z));

            }

            int edge,v1,v2,v3;
            
            for(int i = 0; i < nfaces; i++)
            {
                file>> edge >> v1 >>v2 >> v3;
                m_Faces.push_back(make_tuple(v1,v2,v3));
            }
        }
        void SetAngles()
        {
            
            for(int i = 0; i < nfaces; i++)
            {
                for(int j = 0; j < nfaces; j++)
                {
                    if (i!=j)
                    {
                        auto Diff=getDiff(m_Faces[i],m_Faces[j]);
                        auto pDiff=Diff.first;
                        auto vEq=Diff.second;

                        Weights[pDiff]=01;
                    }
                    
                }   
            }
            
        }

        void showWeights()
        {
            for (auto i: this->Weights)
            {
                auto tupla=i.first;
                cout<< tupla.first <<", "<<tupla.second<<" -> "<<i.second<<endl;

            }
        }
};



int main()
{
    Model modelo;
    modelo.ReadOff("test.off");
    modelo.SetAngles();
    //modelo.showWeights();

    //modelo.PrintOFF();

    tuple<int,int,int> t1(1,4,5);
    tuple<int,int,int> t2(3,5,1);

    
    auto diff=modelo.getDiff(t1,t2);
    auto pD=diff.first;
    auto vD=diff.second;
    cout<<"After: "<<pD.first<<" "<<pD.second<<endl;
    cout<<"After: "<<pD.first<<" "<<pD.second<<endl;

    vector<double> v=getVector(t2,t1);
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;

}





