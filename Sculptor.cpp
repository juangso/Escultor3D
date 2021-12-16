#include "Sculptor.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


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

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if((i>=x0 && i <= x1) && (j>=y0 && j <= y1) && (k>=z0 && k <= z1)){
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if((i>=x0 && i <= x1) && (j>=y0 && j <= y1) && (k>=z0 && k <= z1)){
                    v[i][j][k].isOn = false;
                }
            }
        }
    }

};

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(((pow(i-xcenter,2)) + pow(j-ycenter,2) + pow(k-zcenter,2)) < pow(radius,2)) {
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }

};

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(((pow(i-xcenter,2)) + pow(j-ycenter,2) + pow(k-zcenter,2)) <= pow(radius,2)) {
                    v[i][j][k].isOn = false;
                }
            }
        }
    }

};

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(((pow(i-xcenter,2)/pow(rx,2))+(pow(j-ycenter,2)/pow(ry,2))+(pow(k-zcenter,2)/pow(rz,2))) < 1)  {
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                    v[i][j][k].isOn = true;
                }
            }
        }
    }

};

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(((pow(i-xcenter,2)/pow(rx,2))+(pow(j-ycenter,2)/pow(ry,2))+(pow(k-zcenter,2)/pow(rz,2))) < 1)  {
                    v[i][j][k].isOn = false;
                }
            }
        }
    }

};


void Sculptor::writeOFF(char* filename){
    int nVoxel = 0; //variavel para armazenar a quant de voxels da figura
    
    //contagem da quant de voxels
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(v[i][j][k].isOn){
                    nVoxel++;
                }
            }
        }
    }

    ofstream off(filename); //abertura do fluxo para escrita no arquivo .off
    
    //escrita do arquivo .off
    //cabeçalho do arquivo
    off << "OFF\n" << 8*nVoxel << " " << 6*nVoxel << " 0" << endl;

    //escrita das coordenadas dos vértices
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(v[i][j][k].isOn){
                    off << i-0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    off << i-0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    off << i+0.5 << " " << j-0.5 << " " << k-0.5 << endl;
                    off << i+0.5 << " " << j+0.5 << " " << k-0.5 << endl;
                    off << i-0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                    off << i-0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    off << i+0.5 << " " << j-0.5 << " " << k+0.5 << endl;
                    off << i+0.5 << " " << j+0.5 << " " << k+0.5 << endl;
                }
            }
        }
    }

    a = 0;
    //escrita das faces
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                if(v[i][j][k].isOn){
                    off  << 4 << " " << 8*a << " " << 8*a+3 << " " << 8*a+2 << " " << 8*a+1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    off  << 4 << " " << 8*a+4 << " " << 8*a+5 << " " << 8*a+6 << " " << 8*a+7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    off  << 4 << " " << 8*a << " " << 8*a+1 << " " << 8*a+5 << " " << 8*a+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    off  << 4 << " " << 8*a << " " << 8*a+4 << " " << 8*a+7 << " " << 8*a+3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    off  << 4 << " " << 8*a+3 << " " << 8*a+7 << " " << 8*a+6 << " " << 8*a+2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << endl;
                    off  << 4 << " " << 8*a+1 << " " << 8*a+2 << " " << 8*a+6 << " " << 8*a+5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " <<v[i][j][k].b << " " << v[i][j][k].a << endl;

                    a++;
                }
                
            }
        }
    }


    
    

}