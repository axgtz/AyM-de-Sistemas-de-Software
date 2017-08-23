//
//  main.cpp
//  Singleton
//
//  Created by Alex Gutz on 8/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

#include <string>

using namespace std;

class Reloj{
private:
    double time;
public:
    //Constructor
    Reloj(){
    }
    
    float getTime(){
        return time;
    }
    void setTime(double t){
        time = t;
    }
    
    void imprimirDatos(){
        cout << "Time:" <<  time << endl;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
