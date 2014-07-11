/* 
 * File:   Worker.cpp
 * Author: marie
 * 
 * Created on July 3, 2014, 6:37 PM
 */

#include <iostream>
#include "World.hh"

extern "C" {
#include "zappy.h"
}
#include "IGameElement.hh"

World::World(ISafeQueue<t_data*>* eventQueue, ISafeQueue<t_data*>* commandQueue)
: _eventQueue(eventQueue), _commandQueue(commandQueue)
{
    if (zc_ctor(&_zc) == RET_FAILURE)
    {
//	std::cout << "Zc Initialization failed: %s\n" << (errno == 0 ? "Unknown error" : strerror(errno)) << std::endl;
	throw std::string("Zc Initialization failed");
    }
    
    world_ctor(&_world, this);

    std::string host_string("127.0.0.1");
    char *host = const_cast<char *>(host_string.c_str());
    int port = 4242;
    
    std::cout << "Connecting to" << host << port << std::endl;
    if (zc_connect(&_zc, host, port) == RET_FAILURE);
//    if (zc_connect(&_zc, host, port) == RET_FAILURE)
//    {
//	throw std::string("Connection failed");
//    }
    zc_send_graphic(&_zc);
}
World::~World()
{
    world_dtor(&_world);
    zc_dtor(&_zc);
}

void* World::routine()
{
    zc_main(&_zc);
    //	world_loop(&_world);
    return nullptr;
}

void World::push_callback(t_data* data)
{
    _eventQueue->push(new t_data(*data));
}
bool World::try_pop_command(t_data* data)
{
    return _commandQueue->tryPop(data);
}


//Worker::Worker()
//{
//}
//
//Worker::~Worker()
//{
//}

