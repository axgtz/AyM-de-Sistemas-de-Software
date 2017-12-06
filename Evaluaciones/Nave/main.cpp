//
//  main.cpp
//  Naves
//
//  Created by Alex Gutz on 10/25/17.
//  Copyright © 2017 Alex Gutz. All rights reserved.
#include <iostream>
#include <vector>

int tablero [10][10];
int contEliminados = 0;
using namespace std;

template <class T>
class TIterator;

void imprimirTablero(){
    for(int i = 0; i<=9;i++){
        for(int j = 0; j<=9;j++){
            cout << tablero[i][j] << "  " ;
        }
        cout << endl;
    }
    cout << "\n";
}

class Papa{
protected:
    int posX;
    int posY;
    string nombre;
    Papa(){}
public:
    virtual int getPosX(){return posX;}
    virtual int getPosY(){return posY;}
    virtual string getNombre(){return nombre;}
    virtual void mover(bool colision){}
};

class Observer{
protected:
    string name;
public:
    virtual void colision(string anuncioCol)=0;
};

template <class T>
class TCollection {
protected:
    int size;
    T* array;
    int cont = 0;
public:
    friend class TIterator<T>;
    TCollection() {
        size = 7;//-------
        array = new T[size];
    }
    void add(T value) {
        if (cont < size) {
            array[cont++] = value;
            return;
        }
        cout << "Ya no hay espacio para agregar elementos";
    }
    TIterator<T> * getIterator();

    T at(int pos) {    //Devuelve un elemento en una posiciÛn
        return array[pos];
    }
};

template <class T>
class TIterator {
protected:
    TCollection<T> coll;
    int cont = 0;
public:
    TIterator(const TCollection<T>& coll) : coll(coll) {}

    bool hasNext() {
        if (cont < coll.cont)
            return true;
        return false;
    }

    T next() {//Devuelve T
        return coll.at(cont++);
    }
    //Delete
    T deletePrev() {
        return coll.at(cont++);
    }
};

template <class T>
TIterator<T>* TCollection<T>::getIterator() {
    return new TIterator<T>(*this);
}

class POS : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    POS(){
        nombre = "POS";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static POS* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static POS* getInstance(){
        if(!single_instance){
            single_instance = new POS();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de POS: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 &&  tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 &&  tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 &&  tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 &&  tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    POS* POS::single_instance = 0;


class PlanetExplorationShip : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    PlanetExplorationShip(){
        nombre = "PlanetExplorationShip";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static PlanetExplorationShip* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static PlanetExplorationShip* getInstance(){
        if(!single_instance){
            single_instance = new PlanetExplorationShip();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de PlanetExplorationShip: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 &&  tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 &&  tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 &&  tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 &&  tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    PlanetExplorationShip* PlanetExplorationShip::single_instance = 0;


class PlanetColonisationShip : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    PlanetColonisationShip(){
        nombre = "PlanetColonisationShip";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static PlanetColonisationShip* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static PlanetColonisationShip* getInstance(){
        if(!single_instance){
            single_instance = new PlanetColonisationShip();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de PlanetColonisationShip: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 &&  tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 &&  tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 &&  tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 && tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    PlanetColonisationShip* PlanetColonisationShip::single_instance = 0;


class IronMeteorite : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    IronMeteorite(){
        nombre = "IronMeteorite";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static IronMeteorite* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static IronMeteorite* getInstance(){
        if(!single_instance){
            single_instance = new IronMeteorite();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de IronMeteorite: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 &&  tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 &&  tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 &&  tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 &&  tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    IronMeteorite* IronMeteorite::single_instance = 0;

class StoneMeteorite : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    StoneMeteorite(){
        nombre = "StoneMeteorite";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static StoneMeteorite* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static StoneMeteorite* getInstance(){
        if(!single_instance){
            single_instance = new StoneMeteorite();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de StoneMeteorite: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 &&  tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 &&  tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 &&  tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 &&  tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    StoneMeteorite* StoneMeteorite::single_instance = 0;

class DesertPlanet : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    DesertPlanet(){
        nombre = "DesertPlanet";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static DesertPlanet* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static DesertPlanet* getInstance(){
        if(!single_instance){
            single_instance = new DesertPlanet();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de DesertPlanet: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 && tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 &&  tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 &&  tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 &&  tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    DesertPlanet* DesertPlanet::single_instance = 0;


class EarthAnalog : public Observer, public Papa{
private:
    int posX;
    int posY;
    string nombre;
    EarthAnalog(){
        nombre = "EarthAnalog";
        posX = (rand() % 9);
        posY = (rand() % 9);
        tablero[posX][posY]++;
    }
protected:
    static EarthAnalog* single_instance;
public:
    //Puede que neceiste ser estatico
    int getPosX(){return posX;}
    int getPosY(){return posY;}
    string getNombre(){return nombre;}
    static EarthAnalog* getInstance(){
        if(!single_instance){
            single_instance = new EarthAnalog();
        }
        return single_instance;
    }
    void colision(string anuncio){
        cout << "Colision de EarthAnalog: " << anuncio << "\n";
    }
    void mover(bool colision){
        if(!colision){
            if(posY < 9 &&  tablero[posX][posY+1] != -1){//no cambia X
                tablero[posX][posY]--;
                posY++;
                tablero[posX][posY]++;
            }else if(posY > 0 && tablero[posX][posY-1] != -1){
                tablero[posX][posY]--;
                posY--;
                tablero[posX][posY]++;
            }else if(posX > 0 && tablero[posX-1][posY] != -1){
                tablero[posX][posY]--;
                posX--;
                tablero[posX][posY]++;
            }else if(posX < 9 && tablero[posX+1][posY] != -1){
                tablero[posX][posY]--;
                posX++;
                tablero[posX][posY]++;
            }
            //cout << posX << " - " << posY << "\n";
        }
        delete single_instance;
    }
};    EarthAnalog* EarthAnalog::single_instance = 0;

class Subject{
    vector<Observer*> lista;
public:
    void addObservador(Observer * observer){
        lista.push_back(observer);
    }
    void anunciarCol(string anuncioCol){
        for(int i = 0; lista.size() > i; i++)
            lista[i]->colision(anuncioCol);
    }
};
template <class T>
class Narrador : public Subject{
    TCollection<Papa*> coll;
public:
    void addObjeto(Papa * instance){
        coll.add(instance);
    }
    void checarTablero(){
        TIterator<Papa*> * it = coll.getIterator();

        while(contEliminados < 7){
            imprimirTablero();
            for(int i = 0; i<=9;i++){
                for(int j = 0; j<=9;j++){
                    if(tablero[i][j]>1){//Existe Colision
                        it = coll.getIterator();
                        while (it->hasNext()) { //Busca que instancias estaban en la colision
                            cout << "has next"<< endl;
                            Papa * naxt = it->next();
                            if(naxt->getPosX()==i && naxt->getPosY()==j){//Equivalente a anunciar
                                tablero[i][j] = -1;//Escribir en tablero colision
                                //Indicar que hubo colision y destruir
                                naxt->mover(true);//++++++++++++++++Deberian ser eliminados
                                contEliminados++;
                                cout << "-----El objeto: "<< naxt->getNombre() << " fue turbo eliminado----\n";
                            }
                        }
                    }
                }
            }
            it = coll.getIterator();
            //----Instancias se muevan usando iterador
            while (it->hasNext()) {
                Papa * naxt = it->next();
                naxt->mover(false);
                //cout << naxt->getNombre() << " se movió "<< endl;
            }
        }
    }
};

//Hacer movimiento random con un switch y un bool si se movio, modif clase obs y subj, checar tqablero cuando col llegue a 0 parar
int main(int argc, const char * argv[]) {
    //Inicializar tablero en ceros
    for(int i = 0; i<=9;i++){
        for(int j = 0; j<=9;j++){
            tablero[i][j] = 0;
        }
    }
    PlanetColonisationShip* instancePCS = PlanetColonisationShip::getInstance();
    POS* instancePOS = POS::getInstance();
    PlanetExplorationShip* instancePES = PlanetExplorationShip::getInstance();
    StoneMeteorite* instanceSM = StoneMeteorite::getInstance();
    IronMeteorite* instanceIM = IronMeteorite::getInstance();
    DesertPlanet* instanceDP = DesertPlanet::getInstance();
    EarthAnalog* instanceEA = EarthAnalog::getInstance();

    //Crear clase Narrador(Subject), llamar a checar tablero y mandarle la coleccion
    Narrador<Papa> * freeman = new Narrador<Papa>();
    freeman->addObjeto(instancePCS);
    freeman->addObjeto(instancePOS);
    freeman->addObjeto(instancePES);
    freeman->addObjeto(instanceSM);
    freeman->addObjeto(instanceIM);
    freeman->addObjeto(instanceDP);
    freeman->addObjeto(instanceEA);
    freeman->checarTablero();

    return 0;
}
