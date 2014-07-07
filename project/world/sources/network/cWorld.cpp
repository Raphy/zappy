/* 
 * File:   cWorker.cpp
 * Author: marie
 * 
 * Created on July 3, 2014, 6:44 PM
 */


extern "C" {
#include "zappy.h"
}

#include <iostream>
#include <unistd.h>
#include "World.hh"
#include "cWorld.hh"


#include "ILevel.hh"
#include "MapObject.hh"

//typedef	void	(t_zsh_basic)(t_zs *zs, void *data);
//
//typedef	void	(t_zsh_client_basic)(t_zs *zs, t_zc *zc, void *data);
//
//typedef	void	(t_zsh_str_basic)(t_zs *zs, t_zc *zc, const char *str, void *d);
//
//void world_ctor(t_world * self, Worker * cpp_world)
//{
////  t_zc		zc;
//  
//  std::cout << "world_ctor" << std::endl;
//    self->cpp_world = cpp_world;
//
//    //set handlers
////  zc_hook_errno(this->zc, &remote_errno_handler, this);
////  zc_hook_connected(this->zc, &remote_connected_handler, this);
////  zc_hook_disconnected(this->zc, &remote_disconnected_handler, this);
////  zc_hook_timeout(this->zc, &remote_timeout_handler, this);
//
//  zc_hook_cmd_msz(cpp_world->getZc(), &world_msz_handler, (void*)self);
//}
//
//void world_dtor(t_world * self)
//{
//    (void)self;
//    std::cout << "world_dtor" << std::endl;
//}
//
//// au final ne fera que appeler zappy_main
//void world_loop(t_world * self)
//{
//    (void)self;
//    while (42)
//    {
//	//do handler
//        std::cout << "world_loop" << std::endl;
//	sleep(1);
//    }
//}


/* CALLBACKS C */

void world_basic_handler(void *world) // doit respecter typedef handler zappy
{
    // rempli basique structure
    t_world * self = static_cast<t_world *>(world);
    self->cpp_world->push_callback(self->data);//push real_data ??
}

void world_level_handler(void *world, int level) // doit respecter typedef handler zappy
{
    t_world * self = static_cast<t_world *>(world);

//    self->data->realptr = &ILevel::setLevel;
//    self->data->ptr_type = INT_HANDLER;
    self->data->game_element_type = PERSO_CLASS;

    self->data->infos->level = level;

    self->cpp_world->push_callback(self->data);
}

void	world_msz_handler(t_zc *zc, t_msz *msz, void *world)
{
    (void)zc;
    t_world * self = static_cast<t_world *>(world);

    self->data->event_type = MAP_SIZE_EVENT;
    self->data->game_element_type = MAP_CLASS;

    self->data->infos->x = msz->width;
    self->data->infos->y = msz->height;

    self->cpp_world->push_callback(self->data);    
}
//__attribute__((unused))t_zc *zc,
//				     int err, const char *msg,
//				     __attribute__((unused))void *data
void	world_errno_handler(t_zc *zc, int err, const char *msg, void *world)
{
    (void)zc;
    t_world * self = static_cast<t_world *>(world);

    self->data->event_type = ERRNO_EVENT;
    self->data->game_element_type = ENGINE_CLASS;

    self->data->infos->err = err;
    self->data->infos->msg = msg;

    self->cpp_world->push_callback(self->data);    
}

void	world_connected_handler(t_zc *zc, void *world)
{
    (void)zc;
    t_world * self = static_cast<t_world *>(world);

    self->data->event_type = CONNECTED_EVENT;
    self->data->game_element_type = ENGINE_CLASS;

    self->cpp_world->push_callback(self->data);    
}
