#ifndef GPS_H
#define GPS_H

#include "Model.h"
#include <fstream>


class GPS
{
    private:
        Model *h;
        string filename;
    public:
        GPS(string);
        void getGPSFromFile(string, int, int, bool);
        void getAllGPS();
        ~GPS();
};

GPS::GPS(string filename)
{
    this->filename = filename;
    this->h = new Model;
}

void GPS::getGPSFromFile(string file,int nEigen, int K, bool invertido){
    this->h->ReadOff(file);
    this->h->SetAngles();
    this->h->setOLBValues();
    this->h->setEigen(nEigen);
    this->h->getGPS(K,invertido);
}

void GPS::getAllGPS(){
    fstream file;
    file.open(this->filename);
    string line;
    while(!file.eof()){
        file>>line;
        this->getGPSFromFile("animales/"+line,30,30,false);
    }
}


GPS::~GPS()
{
}



#endif