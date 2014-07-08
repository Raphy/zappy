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
#include <tuple>
#include "World.hh"
#include "cWorld.hh"

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


/* CALLBACKS C */

void	world_errno_handler(__attribute__((unused)) t_zc *zc, int err, const char *msg, void *world)
{
    t_world * self = static_cast<t_world *>(world);

    self->data->event_type = ERRNO_EVENT;
    self->data->game_element_type = ENGINE_CLASS;

    self->data->infos->err = err;
    self->data->infos->msg = msg;

    self->cpp_world->push_callback(self->data);    
}

void	world_connected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = static_cast<t_world *>(world);

    self->data->event_type = CONNECTED_EVENT;
    self->data->game_element_type = ENGINE_CLASS;

    self->cpp_world->push_callback(self->data);    
}

void	world_msz_handler(__attribute__((unused)) t_zc *zc, t_msz *msz, void *world)
{
    t_world * self = static_cast<t_world *>(world);

    self->data->event_type = MAP_SIZE_EVENT;
    self->data->game_element_type = MAP_CLASS;

    self->data->infos->x = msz->width;
    self->data->infos->y = msz->height;

    self->cpp_world->push_callback(self->data);    
}

