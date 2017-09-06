//  Created by Alex Gutz on 9/6/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved. A01019608
#include "Menu.hpp"

int main(int argc, const char * argv[]) {
    //1-Desktop, 2-Laptop, 3-Netbook, 4-Tablet, 5-ServerRack, 6-ServerTower
    Menu m;
    
    //
    Computadora* c = m.crearComputadoras(1);
    c->empaquetadoComputador();
    
    
    
    return 0;
}
