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
    if (zc_connect(&_zc, host, port) == RET_FAILURE)
    {
	throw std::string("Connection failed");
    }
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
    _eventQueue->push(data);
}
t_data* World::pop_command()
{
    //	t_data command_data;
    //	_commandQueue->tryPop(&command_data);
    return nullptr;
}

static void init_infos(t_infos *i)
{
    i->x = -1;
    i->y = -1;
    i->orientation = -1;
    i->level = -1;
    i->quantity = -1;
    i->player_id = -1;//list ?
    i->egg_id = -1;
    i->ressource_id = -1;
    i->time_unit = -1;
    i->team_name = nullptr;
    i->err = -1;
    i->msg = nullptr;    
}

void world_ctor(t_world * self, World * cpp_world)
{
//  t_zc		zc;
  t_infos		infos;
  t_data		data;
  
  std::cout << "world_ctor" << std::endl;
    self->cpp_world = cpp_world;

    init_infos(&infos);
    data.infos = &infos;
    data.event_type = EVENT_COUNT;
    data.game_element_type = HANDLER_CLASS_COUNT;
    self->data = &data;

    //set handlers
  zc_hook_errno(cpp_world->getZc(), &world_errno_handler, self);
  zc_hook_connected(cpp_world->getZc(), &world_connected_handler, self);
//  zc_hook_disconnected(this->zc, &remote_disconnected_handler, this);
//  zc_hook_timeout(this->zc, &remote_timeout_handler, this);

  zc_hook_cmd_msz(cpp_world->getZc(), &world_msz_handler, self);
}

void world_dtor(t_world * self)
{
    (void)self;
    std::cout << "world_dtor" << std::endl;
}

// au final ne fera que appeler zappy_main
void world_loop(t_world * self)
{
    (void)self;
//    while (42)
//    {
//	//do callback
//        std::cout << "world_loop" << std::endl;
//	sleep(1);
//    }
}


//Worker::Worker()
//{
//}
//
//Worker::~Worker()
//{
//}

