#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class eucVector
{
    private:
        vector<double> m_eucVector;
    public:
        eucVector() { }

        void push_back(double v)
        {
            m_eucVector.push_back(v);
        }

        double operator[] (int i)
        {
            return this->m_eucVector[i];
        }

        double getModule()
        {
            double res=0;
            for(auto i:m_eucVector)
            {
                res+=pow(i,2);
            }
            return pow(res,0.5);
        }
        

        ~eucVector() { }

        friend ostream& operator << (ostream &o,const eucVector &p);
};

ostream& operator << (ostream &o,const eucVector &p)
{
    cout<<"[ ";
    for (auto i: p.m_eucVector)
    {
        cout<<i<<" ";
    }
    cout<<"]"<<endl;
    return o;
}