/* 
 * File:   main.cpp
 * Author: marie
 *
 * Created on June 30, 2014, 12:45 PM
 */

#include <iostream>

#include "Helper.hh"

using namespace std;

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    Helper* helper = nullptr;  
    IEngine* engine = nullptr;  
    try
    {
        helper = Helper::getInstance(argc, argv);
	engine = helper->createEngine();
    }
    catch (std::string& msg)
    {
	std::cout << "Initialization error : " << msg << std::endl;
	return 1;
    }
    if (engine->init())
        engine->mainLoop();
    delete engine;
    return 0;
}

