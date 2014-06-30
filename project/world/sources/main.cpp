/* 
 * File:   main.cpp
 * Author: marie
 *
 * Created on June 30, 2014, 12:45 PM
 */

#include "Binder.hh"

using namespace std;

int main(int argc, char** argv)
{
    Binder* binder = Binder::getInstance();
    IEngine* engine = binder->createEngine();
    engine->init();
    engine->mainLoop();
    return 0;
}

