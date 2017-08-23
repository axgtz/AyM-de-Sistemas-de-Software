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
        cout << "Funciona" << endl;
    }
};

Singleton* Singleton::single_instance = 0;


int main(int argc, const char * argv[]) {

    Singleton* instance = Singleton::getInstance();
    instance->operacion();
    
    return 0;
}
