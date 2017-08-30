//
//  crtpInheritePrototype.cpp
//  Prototype
//
//  Created by Alex Gutz on 8/30/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.

#include <iostream>
using namespace std;

class Mundo {
public:
    Mundo(string mundo) : nombreMundo(mundo){}
    string nombreMundo;
};

class Personaje {
public:
    Personaje() = default;
    Personaje(string nombre) : nombre(nombre){}
    string nombre;
    int telefono;
    Mundo* mundo;
    string correo;
    virtual Personaje* clone() = 0;
};

template<class Base, class SubClass> //Recibe subclase y clase padre
class Clone : public Base{
public:
    Base* clone(){
        return new SubClass(dynamic_cast<SubClass&>(*this)); //Se devuelve algo generico
    }
};

class Princesa : public Clone<Personaje, Princesa>{
public:
    Princesa(string n){
        nombre = n;
    }
    
    Princesa(const Princesa& p){
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo ->nombreMundo); //Se crea nueva instancia de mundo con el mismo nombre del munod original
    }
    
    void grita(){
        cout << "Ayyyy Ayudaa!!!"<<endl;};
};


int main(){
        Princesa* prin = new Princesa("Rapunzel");
        prin->correo = "yolo@swag.com";
        prin->telefono = 553233232;
        prin->mundo = new Mundo("Paleta");
        
        Princesa* p = dynamic_cast<Princesa*>(prin->clone());
        prin->nombre = "RAPUNZEL";
        prin->mundo->nombreMundo = "Paletón";
        
        cout << p->nombre <<endl;
        cout << p->correo <<endl;
        cout << p->telefono <<endl;
        
        Princesa* pp = dynamic_cast<Princesa*>(p->clone());
        pp->mundo->nombreMundo = "Paletita";
        
        cout << pp->mundo->nombreMundo <<endl;
        
        return 0;
}
