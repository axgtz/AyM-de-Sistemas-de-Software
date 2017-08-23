//
//  main.cpp
//  Singleton
//
//  Created by Alex Gutz on 8/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton(){} //Como el constructor es privado ya no te deja hacer una instancia sin apuntador,
protected:
    //La variable tine que ser estatica para que el metodo estatica pueda acceder a ella
    static Singleton* single_instance;
    
public:
    static Singleton* getInstance(){
        if(!single_instance){
            single_instance = new Singleton;
        }
        return single_instance;
    }
    
    void operacion(){
        cout << "Funciona - Direccion: "<< single_instance << endl;
    }
};

Singleton* Singleton::single_instance = 0;


int main(int argc, const char * argv[]) {

    Singleton* instance = Singleton::getInstance();
    instance->operacion();
    
    Singleton* instance2 = Singleton::getInstance();
    instance2->operacion();
    
    Singleton* instance3 = Singleton::getInstance();
    instance3->operacion();
    
    Singleton* instance4 = Singleton::getInstance();
    instance4->operacion();
    
    return 0;
}
