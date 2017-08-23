//
//  main.cpp
//  FactoryMethod
//
//  Created by Alex Gutz on 8/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;

class Product{
public:
    void operation(){
        cout << "estoy en operación" << endl ;
    }
    
    void operation2(){
        cout << "estoy en operación 2222" << endl;
    }
    
};

class Creator {
private:
    virtual Product* createProduct(int type) = 0;

public:
    Product* factoryMethod(int type){ //Delega la creación a un método virtual puro(privado)y ese lo manda al hijo
        Product *p = createProduct(type);
        p->operation();
        return p;
    }
};

class CreatorA : public Creator{
public:
    Product* createProduct(int type)
    {
        if (type == 1)
            return new Product;
        return new Product;//Guard condition, el default
    }
};

/*
int main(int argc, const char * argv[]) {
    //Creator debería ser singleton y creator concretos(creatorA) con constructor privado
    Creator* c = new CreatorA;
    Product* p = c->factoryMethod(1);
    p->operation2();
    
    delete p;
    delete c;
    
    return 0;
}*/
