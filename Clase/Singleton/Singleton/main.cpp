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
    static Singleton *single_instance;

    static Singleton *instance(){
        if(!single_instance){
            single_instance = new Singleton;
        }
        return single_instance;
    }
    
    void operacion(){
        
    }
};



int main(int argc, const char * argv[]) {

    std::cout << "Hello, World!\n";
    return 0;
}
