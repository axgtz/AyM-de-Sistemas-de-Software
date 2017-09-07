//  Computadora.hpp
//  Created by Alex Gutz on 9/6/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.

#ifndef Computadora_hpp
#define Computadora_hpp

#include <iostream>

using namespace std;

class Computadora{
protected:
    Computadora(){};
public:

    virtual Computadora* clone() = 0;

    virtual void seleccionComponentes() = 0;
    virtual void ensambladoComponentes() = 0;
    virtual void instalacionYConfigSoft() = 0;
    virtual void empaquetadoComputador() = 0;
    
    //Fabrica
    template<class SubClase>
    static SubClase* crearComputadora(){
        SubClase* finalComp = new SubClase;
        
        return finalComp;
    }

};

template <class SubClase>
class ClonComputadora : public Computadora{
public:
    Computadora* clone(){
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Desktop : public ClonComputadora<Desktop>{
protected:
    Desktop(){};
public:
    friend Computadora;
    void seleccionComponentes(){
        cout << "Desktop: Seleccionando componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "Desktop: Ensamblando componentes" << endl;
    }
    void instalacionYConfigSoft(){
        cout << "Desktop: Instalando y configurando el software" << endl;
    }
    void empaquetadoComputador(){
        cout << "Desktop: Empaquetando la computadora" << endl;
    }
};



class Laptop : public ClonComputadora<Laptop>{
protected:
    Laptop(){};
public:
    friend Computadora;
    void seleccionComponentes(){
        cout << "Laptop: Seleccionando componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "Laptop: Ensamblando componentes" << endl;
    }
    void instalacionYConfigSoft(){
        cout << "Laptop: Instalando y configurando el software" << endl;
    }
    void empaquetadoComputador(){
        cout << "Laptop: Empaquetando la computadora" << endl;
    }
};

class Netbook : public ClonComputadora<Netbook>{
protected:
    Netbook(){};
public:
    friend Computadora;

    void seleccionComponentes(){
        cout << "Netbook: Seleccionando componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "Netbook: Ensamblando componentes" << endl;
    }
    void instalacionYConfigSoft(){
        cout << "Netbook: Instalando y configurando el software" << endl;
    }
    void empaquetadoComputador(){
        cout << "Netbook: Empaquetando la computadora" << endl;
    }
};

class Tablet : public ClonComputadora<Tablet>{
protected:
    Tablet(){};
public:
    friend Computadora;

    void seleccionComponentes(){
        cout << "Tablet: Seleccionando componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "Tablet: Ensamblando componentes" << endl;
    }
    void instalacionYConfigSoft(){
        cout << "Tablet: Instalando y configurando el software" << endl;
    }
    void empaquetadoComputador(){
        cout << "Tablet: Empaquetando la computadora" << endl;
    }
};

class ServerRack : public ClonComputadora<ServerRack>{
protected:
    ServerRack(){};
public:
    friend Computadora;

    void seleccionComponentes(){
        cout << "ServerRack: Seleccionando componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "ServerRack: Ensamblando componentes" << endl;
    }
    void instalacionYConfigSoft(){
        cout << "ServerRack: Instalando y configurando el software" << endl;
    }
    void empaquetadoComputador(){
        cout << "ServerRack: Empaquetando la computadora" << endl;
    }
};

class ServerTower : public ClonComputadora<ServerTower>{
protected:
    ServerTower(){};
public:
    friend Computadora;
    
    void seleccionComponentes(){
        cout << "ServerTower: Seleccionando componentes" << endl;
    }
    void ensambladoComponentes(){
        cout << "ServerTower: Ensamblando componentes" << endl;
    }
    void instalacionYConfigSoft(){
        cout << "ServerTower: Instalando y configurando el software" << endl;
    }
    void empaquetadoComputador(){
        cout << "ServerTower: Empaquetando la computadora" << endl;
    }
};

#endif /* Computadora_hpp */
