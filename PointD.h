#include "eucVector.h"
#include "ErrorMessages.h"


template <int N>
class PointD
{
    private:
        int m_size=N;
        vector<double> m_Point;
    public:
        PointD()
        {
            
            for(int i = 0; i < N; i++)
            {
                this->m_Point.push_back(0);
            }
            
        }
        PointD(vector<double> point){
            if (point.size()==this->m_size)
                this->m_Point=point;
            else
            {
                cout<<"Point: ( ";
                for (auto i: point){
                    cout<<i<<" ";
                }
                cout<<") doesn't have "<<N<<" elements."<<endl;
                exit(-1);
            }
        }

        int size()
        {
            return this->m_size;
        }

        double operator[] (int i)
        {
            return this->m_Point[i];
        }

        template<int O>
        bool operator == (PointD<O> &p)
        {
            if (p.size()!=this->size()){
                cout<<DIFFERENT_POINTS_SIZE<<endl;
                exit(-1);
            }
            else{
                for(int i = 0; i < N; i++)
                {
                    if (p[i]!=this->m_Point[i]){
                        return false;
                    }
                }
                return true;
            }
        }

        template<int O>
        eucVector operator - (PointD<O> &p)
        {
            if (O!=N)
            {
                cout<<DIFFERENT_POINTS_SIZE<<endl;
                exit(-1);
            }
            
            eucVector res;
            
            for(int i = 0; i < O; i++)
            {
                res.push_back(this->m_Point[i]-p[i]);
            }
            return res;
            
            
        }


        template<int O>
        friend ostream& operator << (ostream &o,const PointD<O> &p);

        ~PointD(){}
};

template <int N>
ostream& operator << (ostream &o,const PointD<N> &p)
{
    for (auto i: p.m_Point)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return o;
}