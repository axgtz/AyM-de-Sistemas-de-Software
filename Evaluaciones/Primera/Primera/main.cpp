//  Created by Alex Gutz on 9/6/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved. A01019608
#include "Menu.hpp"

int main(int argc, const char * argv[]) {
    //1-Desktop, 2-Laptop, 3-Netbook, 4-Tablet, 5-ServerRack, 6-ServerTower
    Menu m;
    
    //Desktop
    Computadora* c = m.crearComputadoras(1);
    c->seleccionComponentes();
    c->ensambladoComponentes();
    c->instalacionYConfigSoft();
    c->empaquetadoComputador();
    cout << endl;
    
    //Laptop
    Computadora* l = m.crearComputadoras(2);
    l->seleccionComponentes();
    l->ensambladoComponentes();
    l->instalacionYConfigSoft();
    l->empaquetadoComputador();
    cout << endl;

    //Netbook
    Computadora* n = m.crearComputadoras(3);
    n->seleccionComponentes();
    n->ensambladoComponentes();
    n->instalacionYConfigSoft();
    n->empaquetadoComputador();
    cout << endl;

    //Tablet
    Computadora* t = m.crearComputadoras(4);
    t->seleccionComponentes();
    t->ensambladoComponentes();
    t->instalacionYConfigSoft();
    t->empaquetadoComputador();
    cout << endl;

    //Server Rack
    Computadora* sr = m.crearComputadoras(5);
    sr->seleccionComponentes();
    sr->ensambladoComponentes();
    sr->instalacionYConfigSoft();
    sr->empaquetadoComputador();
    cout << endl;

    //Server Tower
    Computadora* st = m.crearComputadoras(6);
    st->seleccionComponentes();
    st->ensambladoComponentes();
    st->instalacionYConfigSoft();
    st->empaquetadoComputador();
    cout << endl;

    return 0;
}
