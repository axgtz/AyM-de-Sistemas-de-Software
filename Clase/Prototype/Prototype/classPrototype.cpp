//  classPrototype.cpp
//  Prototype
//
//  Created by Alex Gutz on 8/30/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include <string>

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


class Princesa : public Personaje{
public:
    Princesa(string n) : Personaje(n){}
    
    Princesa(const Princesa& p){
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo ->nombreMundo); //Se crea nueva instancia de mundo con el mismo nombre del munod original
    }
    
    void grita(){
        cout << "Ayyyy Ayudaa!!!"<<endl;};
    
    Personaje* clone(){
        return new Princesa(*this);
    }
};


class Villano : public Personaje{
public:
    Villano(string n) : Personaje(n){}
    
    Villano(const Villano& p){
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo ->nombreMundo);
    }
    
    void secuestra(){
        cout << "U r mine hahahahah"<< endl;}
    Personaje* clone(){
        return this;
    }
    
};


class Heroe : public Personaje{
public:
    Heroe(string n) : Personaje(n){}
    
    Heroe(const Heroe& p){//copy contructor
        nombre = p.nombre;
        telefono = p.telefono;
        correo = p.correo;
        mundo = new Mundo(p.mundo ->nombreMundo);
    }
    
    void grita(){
        cout << "Te voy a salvar bella princesa"<<endl;};
    Personaje* clone(){
        return this;
    }
};


int main(int argc, const char * argv[]) {
   
    Princesa* prin = new Princesa("Rapunzel");
    prin->correo = "yolo@swag.com";
    prin->telefono = 553233232;
    
    Princesa* p = dynamic_cast<Princesa*>(prin->clone());
    prin->nombre = "RAPUNZEL";
    prin->mundo->nombreMundo = "Paletón";

    cout << p->nombre <<endl;
    cout << p->correo <<endl;
    cout << p->telefono <<endl;

    return 0;
}














