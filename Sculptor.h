#include <stdlib.h>
class Sculptor {
    public:
        
        struct Voxel
        {
            float r, g, b; //cores
            float a; //transparencia
            bool isOn; //aparece ou não
        };

        Voxel ***v; //matriz 3D

        int x, y, z; //dimensoes
        float r,g,b,a; //cor e transparencia atual de desenho

    public:

        Sculptor(int x_ = 1, int y_ = 1, int z_ = 1); //construtor
        ~Sculptor(); //destrutor
        void setColor(float r, float g, float b, float a); //define a cor e transparencia atual
        void putVoxel(int x, int y, int z); //faz "isOn = true" e atribui a cor e transparencia atual ao Voxel[x][y][z]   
        void cutVoxel(int x, int y, int z); //faz "isOn = false" ao Voxel[x][y][z]
        void writeOFF(char* filename); //grava o arquivo .off
};