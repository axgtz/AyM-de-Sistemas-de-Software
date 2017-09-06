//  Created by Alex Gutz on 9/6/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved. A01019608

#include "Computadora.hpp"

class Menu{
public:
    Computadora* crearComputadoras(int tipo){
        Computadora* d = Computadora::crearComputadora<Desktop>();
        return d;
        /*switch (tipo) {
            case 1:
                break;
            case 2:
                Computadora* l = FactoryComputadora::crearComputadora<Laptop>();
                break;
            default:
                break;
        }*/
    }
};
int main(int argc, const char * argv[]) {
    Menu m;
    Computadora* c = m.crearComputadoras(1);
    c->empaquetadoComputador();
    
    return 0;
}
