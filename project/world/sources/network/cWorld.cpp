/* 
 * File:   cWorker.cpp
 * Author: marie
 * 
 * Created on July 3, 2014, 6:44 PM
 */

#include <iostream>
#include <unistd.h>
#include <tuple>
#include "World.hh"
#include "cWorld.hh"

extern "C" {
#include "zappy.h"
}

void world_ctor(t_world * self, World * cpp_world)
{
    std::cout << "world_ctor" << std::endl;
    self->cpp_world = cpp_world;
    self->data = new t_data();
    
    //set handlers
    zc_hook_errno(cpp_world->getZc(), &world_errno_handler, self);
    zc_hook_connected(cpp_world->getZc(), &world_connected_handler, self);
//    zc_hook_disconnected(this->zc, &remote_disconnected_handler, this);
//    zc_hook_timeout(this->zc, &remote_timeout_handler, this);
    
    zc_hook_cmd_msz(cpp_world->getZc(), &world_msz_handler, self);
    zc_hook_cmd_bct(cpp_world->getZc(), &world_bct_handler, self);
    zc_hook_cmd_tna(cpp_world->getZc(), &world_tna_handler, self);
    
}

void world_dtor(t_world * self)
{
    (void)self;
    std::cout << "world_dtor" << std::endl;
    delete self->data;
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

void	world_connected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->event_type = CONNECTED_EVENT;
    self->data->game_element_type = ENGINE_CLASS;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_disconnected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->event_type = DISCONNECTED_EVENT;
    self->data->game_element_type = ENGINE_CLASS;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_before_select_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    t_data data;
    t_position position;
    
    if (self->cpp_world->try_pop_command(&data))
    {	
	switch(static_cast<int>(data.event_type))
	{
	    case MAP_SIZE_COMMAND:
		zc_send_cmd_msz(zc);
		break;
	    case CASE_CONTENT_COMMAND:
		position.x = data.infos->pos.first;
		position.y = data.infos->pos.second;
		zc_send_cmd_bct(zc, &position);
		break;
	    case MAP_CONTENT_COMMAND:
		zc_send_cmd_mct(zc);
		break;
	    case TEAM_NAME_COMMAND:
		zc_send_cmd_tna(zc);
		break;
	}
    }    
}
void	world_after_select_handler(t_zc *zc, void *world)
{
    world_before_select_handler(zc, world);
}

void	world_stdin_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_cmd_unknow_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_cmd_welcome_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_ok_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_ko_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_errno_handler(__attribute__((unused)) t_zc *zc, int err, const char *msg, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->event_type = ERRNO_EVENT;
    self->data->game_element_type = ENGINE_CLASS;
    
    self->data->infos->err = err;
    self->data->infos->msg = msg;
    
    self->cpp_world->push_callback(self->data);    
}

void	world_msz_handler(__attribute__((unused)) t_zc *zc, t_msz *msz, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->event_type = MAP_SIZE_EVENT;
    self->data->game_element_type = MAP_CLASS;
    
    self->data->infos->pos.first = msz->width;
    self->data->infos->pos.second = msz->height;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_bct_handler(__attribute__((unused)) t_zc *zc, t_bct *bct, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->event_type = CASE_CONTENT_EVENT;
    self->data->game_element_type = CASE_CLASS;
    
    self->data->infos->quantity[static_cast<int>(FOOD)] = bct->items.food;
    self->data->infos->quantity[static_cast<int>(DERAUMERE)] = bct->items.deraumere;
    self->data->infos->quantity[static_cast<int>(LINEMATE)] = bct->items.linemate;
    self->data->infos->quantity[static_cast<int>(MENDIANE)] = bct->items.mendiane;
    self->data->infos->quantity[static_cast<int>(PHIRAS)] = bct->items.phiras;
    self->data->infos->quantity[static_cast<int>(SIBUR)] = bct->items.sibur;
    self->data->infos->quantity[static_cast<int>(THYSTAME)] = bct->items.thystame;
    
    self->data->infos->pos.first = bct->position.x;
    self->data->infos->pos.second = bct->position.y;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_tna_handler(__attribute__((unused)) t_zc *zc, const char *team_name, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->event_type = TEAM_NAME_EVENT;
    self->data->game_element_type = TEAM_MANAGER_CLASS;
    
    self->data->infos->team_name = team_name;
    
    self->cpp_world->push_callback(self->data);
}
