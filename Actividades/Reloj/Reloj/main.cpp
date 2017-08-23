//  main.cpp
//  Reloj
//  Created by Alex Gutz on 8/23/17.
//  Copyright © 2017 Alejandro Gutierrez. All rights reserved.
//

#include <iostream>
#include <time.h>

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
    
    void printTime(){
        time_t t = time(0);   // get time now
        struct tm * now = localtime( & t );
        cout << (now->tm_year + 1900) << '-'
        << (now->tm_mon + 1) << '-'
        <<  now->tm_mday
        << endl;
    }
};

Reloj* Reloj::instance = 0;

int main(int argc, const char * argv[]) {
    
    Reloj* instance = Reloj::getInstance();
    instance->printTime();
    
    return 0;
}
