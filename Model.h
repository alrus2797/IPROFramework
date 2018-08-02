#include <iostream>
#include <armadillo>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <fstream>

#include "Point3D.h"

void imp(vector<int> t, string message="vec")
{
    cout<<message<<": ";
    for(auto i: t)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

class Model
{
    private:
        vector< Point3D >  m_Vertexs;
        vector< tuple<int,int,int> >  m_Faces;
        map < pair<int,int>, double>  m_Weights;

        int nvertices;
        int nfaces;
        int edges;
     
    public:

        pair<pair<int,int>,pair<int,int>> getDiff(tuple<int,int,int>& t1 , tuple<int,int,int>& t2)
        {
            vector<int> s1,s2;
            int v1,v2,v3;

            tie(v1,v2,v3) = t1;
            s1 = {v1,v2,v3};

            tie(v1,v2,v3) = t2;
            s2 = {v1,v2,v3};
            vector<int> diff, eq;

            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            
            // imp(s1,"t1");
            // imp(s2,"t2");

            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if (s1[i]==s2[j])
                    {
                        eq.push_back(s1[i]);
                        break;
                    }
                }

            }
            if (eq.size()<2)
            {
                eq = {-1,-1};
                diff = {-1,-1};
            }
            else{
                for(int i = 0; i < 3; i++)
                {
                    if (s2[i]!=eq[0] && s2[i]!=eq[1])
                    {
                        diff.push_back(s2[i]);
                    }
                    if (s1[i]!=eq[0] && s1[i]!=eq[1])
                    {
                        diff.push_back(s1[i]);
                    }
                }
                sort(diff.begin(),diff.end());
                sort(eq.begin(),eq.end());
                // imp(eq,  "Eq:   ");
                // imp(diff,"DIff: ");
            }
            // cout<<endl;
            return make_pair(make_pair(diff[0],diff[1]),make_pair(eq[0],eq[1]));
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
                    if (i != j)
                    {
                        
                        auto Diff = getDiff(m_Faces[i],m_Faces[j]);
                        auto pEq  = Diff.second;

                        if (pEq.second != -1)
                        {
                            // cout<<"Face's points: "<<vEq.first<<", "<<vEq.second<<endl;
                            // cout<<"   ->  "<<m_Vertexs[vEq.first]<<"   ,    "<<m_Vertexs[vEq.second]<<endl;
                            // cout<<"   DP: "<<pDiff.first<<"   ,   "<<pDiff.second<<endl;
                            auto pDiff = Diff.first;

                            //Puntos Opuestos
                            Point3D pD1 = m_Vertexs[pDiff.first];
                            Point3D pD2 = m_Vertexs[pDiff.second];

                            //Puntos Comunes
                            Point3D pE1 = m_Vertexs[pEq.first];
                            Point3D pE2 = m_Vertexs[pEq.second];

                            //Vectores Primera cara
                            eucVector v1 = pE1-pD1;
                            eucVector v2 = pE2-pD1;

                            //Unpack 
                            
                            m_Weights[pEq]=01;
                        }
                    }
                    
                }   
            }
            
        }

        void showWeights()
        {
            for (auto i: this->m_Weights)
            {
                auto tupla=i.first;
                cout<< tupla.first <<", "<<tupla.second<<" -> "<<i.second<<endl;
            }
        }
};
