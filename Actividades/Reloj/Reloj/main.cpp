//  main.cpp
//  Reloj
//  Created by Alex Gutz on 8/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;

class Reloj {
private:
    Reloj(){}
protected:
    static Reloj* instance;
    
public:
    static Reloj* getInstance(){
        if(!instance){
            instance = new Reloj;
        }
        return instance;
    }
    
    void operacion(){
        cout << "Time"<< instance << endl;
    }
};

Reloj* Reloj::instance = 0;


int main(int argc, const char * argv[]) {
    
    Reloj* instance = Reloj::getInstance();
    instance->operacion();
    
    Reloj* instance2 = Reloj::getInstance();
    instance2->operacion();
    
    Reloj* instance3 = Reloj::getInstance();
    instance3->operacion();
    
    Reloj* instance4 = Reloj::getInstance();
    instance4->operacion();
    
    return 0;
}
