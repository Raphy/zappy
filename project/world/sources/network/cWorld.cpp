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

#include "IEngine.hh"
#include "MapViewer.hh"
#include "MapObject.hh"
#include "CaseObject.hh"
#include "PlayerObject.hh"

extern "C" {
#include "zappy.h"
}

void world_ctor(t_world * self, World * cpp_world)
{
    std::cout << "world_ctor" << std::endl;
    self->cpp_world = cpp_world;
    self->data = new t_data();
    
#define SET_HANDLER(handler_name)\
    zc_hook_##handler_name(cpp_world->getZc(), &world_##handler_name##_handler, self);
#define SET_CMD_HANDLER(handler_name)\
    zc_hook_cmd_##handler_name(cpp_world->getZc(), &world_##handler_name##_handler, self);

//    SET_HANDLER(errno);
    SET_HANDLER(connected);
//    SET_HANDLER(disconnected);

    //    SET_HANDLER(timeout);
    SET_CMD_HANDLER(msz);
    SET_CMD_HANDLER(bct);
//    SET_CMD_HANDLER(tna);
//    SET_CMD_HANDLER(plv);

#undef SET_HANDLER
}

void world_dtor(t_world * self)
{
    (void)self;
    std::cout << "world_dtor" << std::endl;
    delete self->data;
}

/* CALLBACKS C */

void	world_connected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
//    self->data->event_type = CONNECTED_EVENT;
    self->data->game_element_type = ENGINE_CLASS;
    self->data->engine_handler_ptr = &IEngine::connectedHandler;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_disconnected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
//    self->data->event_type = DISCONNECTED_EVENT;
    self->data->game_element_type = ENGINE_CLASS;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_before_select_data(__attribute__((unused)) t_zc *zc, void *world)
{
    (void)world;
//    t_world * self = static_cast<t_world *>(world);
//    t_data data;
//    t_position position;
//    
//    if (self->cpp_world->try_pop_command(&data))
//    {	
//	switch(static_cast<int>(data.event_type))
//	{
//	    case MAP_SIZE_COMMAND:
//		zc_send_cmd_msz(zc);
//		break;
//	    case CASE_CONTENT_COMMAND:
//		position.x = data.infos->pos.first;
//		position.y = data.infos->pos.second;
//		zc_send_cmd_bct(zc, &position);
//		break;
//	    case MAP_CONTENT_COMMAND:
//		zc_send_cmd_mct(zc);
//		break;
//	    case TEAM_NAME_COMMAND:
//		zc_send_cmd_tna(zc);
//		break;
//	}
//    }    
}
void	world_after_select_data(t_zc *zc, void *world)
{
    world_before_select_data(zc, world);
}

void	world_stdin_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_cmd_unknow_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_cmd_welcome_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_ok_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_ko_handler(__attribute((unused)) t_zc *zc, void *world);
void	world_errno_handler(__attribute__((unused)) t_zc *zc, int err, const char *msg, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
//    self->data->event_type = ERRNO_EVENT;
    self->data->game_element_type = ENGINE_CLASS;
    
    self->data->infos->err = err;
    self->data->infos->msg = msg;
    
    self->cpp_world->push_callback(self->data);    
}

void	world_msz_handler(__attribute__((unused)) t_zc *zc, t_msz *msz, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
//    self->data->event_type = MAP_SIZE_EVENT;
    self->data->mapviewer_handler_ptr = &MapViewer::mapSizeHandler;
    self->data->game_element_type = MAP_VIEWER_CLASS;
    
    self->data->infos->pos.first = msz->width;
    self->data->infos->pos.second = msz->height;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_bct_handler(__attribute__((unused)) t_zc *zc, t_bct *bct, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
//    self->data->event_type = CASE_CONTENT_EVENT;
    self->data->case_handler_ptr = &CaseObject::caseContentHandler;
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
    
//    self->data->event_type = TEAM_NAME_EVENT;
    self->data->game_element_type = TEAM_MANAGER_CLASS;
    
    self->data->infos->team_name = team_name;
    
    self->cpp_world->push_callback(self->data);
}
void	world_plv_handler(__attribute__((unused)) t_zc *zc, t_plv *plv, void *world)
{
    t_world * self = static_cast<t_world *>(world);
    
//    self->data->event_type = TEAM_NAME_EVENT;
    self->data->game_element_type = PLAYER_CLASS;
    self->data->player_handler_ptr = &PlayerObject::levelHandler;
    
    self->data->infos->player_id = plv->uid;
    self->data->infos->level = plv->level;
    
    self->cpp_world->push_callback(self->data);
}
