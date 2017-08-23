//
//  templates
//  FactoryMethod
//
//  Created by Alex Gutz on 8/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>

using namespace std;


class FactoryProduct{
public:
    //virtual void operation() = 0; //Todos los hijos necesitan implementar operation
    template<class Fact>
    
    Fact* factoryMethod(){
        return new Fact;
    }
};

class ProdA : public FactoryProduct {
private:
    ProdA(); //De esta forma la creacion es delegada al factory product y no se puede crear el producto A
public:
    void operation(){
        cout << "estoy en el producto A";
    }
};

int main(int argc, const char * argv[]) {
    //Instanciar Producto A
    FactoryProduct* p = new FactoryProduct;
    ProdA * a = p->factoryMethod<ProdA>();//Es como crear un vector y le dices que producto especifico quiere crear
    
    return 0;
}
