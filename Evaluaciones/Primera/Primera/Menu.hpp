//  Menu.hpp
//  Created by Alex Gutz on 9/6/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.

#ifndef Menu_hpp
#define Menu_hpp

#include "Computadora.hpp"

class Menu{
public:
    static Computadora* crearComputadoras(int tipo){
        switch (tipo) {
            case 1:{
                Computadora* d = Computadora::crearComputadora<Desktop>();
                return d;
            }
            case 2:{
                Computadora* l = Computadora::crearComputadora<Laptop>();
                return l;
            }
            case 3:{
                Computadora* n = Computadora::crearComputadora<Netbook>();
                return n;
            }
            case 4:{
                Computadora* t = Computadora::crearComputadora<Tablet>();
                return t;
            }
            case 5:{
                Computadora* sR = Computadora::crearComputadora<ServerRack>();
                return sR;
            }
            case 6:{
                Computadora* sT = Computadora::crearComputadora<ServerTower>();
                return sT;
            }
            default:
                break;
         }
        return NULL;
    }
};

#endif /* Menu_hpp */
