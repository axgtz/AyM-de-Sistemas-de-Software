//
//  main.cpp
//  Observer
//
//  Created by Alex Gutz on 10/4/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include<string>
#include <vector>

using namespace std;

class Observer{
public:
    virtual void anuncio(string anuncio)=0;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
