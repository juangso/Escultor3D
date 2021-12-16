#include "Sculptor.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

    Sculptor s(50,50,50);
    s.setColor(0.75,0.25,0,1);
    s.putEllipsoid(25,25,25,20,10,10);
    
    s.setColor(0.99,0.99,0.99,1);
    s.putBox(20,20,34,34,22,28);
    s.putBox(25,25,34,34,21,29);
    s.putBox(30,30,34,34,22,28);
    s.putBox(14,14,33,33,23,27);
    s.putBox(36,36,33,33,23,27);
    
    s.putBox(17,33,34,34,25,25);
    s.putBox(15,16,33,33,25,25);
    s.putBox(34,35,33,33,25,25);

    s.writeOFF("bola.off");

    
    

}