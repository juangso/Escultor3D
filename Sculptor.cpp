#include "Sculptor.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

//construtor
Sculptor::Sculptor(int x_, int y_, int z_){
    x = x_;
    y = y_;
    z = z_;

    //aloca dinamicamente a matriz do struct Voxel com base nos valores de x, y e z passados nos parametros.
    v = (Voxel***) malloc(x*sizeof(Voxel**));

    for (int i = 0; i < x; i++)
    {
        v[i] = (Voxel**) malloc(y*sizeof(Voxel*));
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
        v[i][j] = (Voxel*) malloc(z*sizeof(Voxel));
        }
    }
    
};

//Destrutor
Sculptor::~Sculptor(){

};

void Sculptor::setColor(float r_, float g_, float b_, float a_){
    r = r_;
    g = g_;
    b = b_;
    a = a_;
};

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(char* filename){
    ofstream off(filename);

    if (off.is_open()){
        off << "ABRIU";
        off.close();
    }
}