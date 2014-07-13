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
#include "TeamManager.hh"
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
    SET_CMD_HANDLER(tna);
    SET_CMD_HANDLER(pnw);
    SET_CMD_HANDLER(ppo);
    SET_CMD_HANDLER(plv);
    SET_CMD_HANDLER(pin);
//    SET_CMD_HANDLER(pex);
//    SET_CMD_HANDLER(pbc);
//    SET_CMD_HANDLER(pic);
//    SET_CMD_HANDLER(pie);
//    SET_CMD_HANDLER(pfk);
//    SET_CMD_HANDLER(pdr);
//    SET_CMD_HANDLER(pgt);
//    SET_CMD_HANDLER(pdi);
//    SET_CMD_HANDLER(enw);
//    SET_CMD_HANDLER(eht);
//    SET_CMD_HANDLER(ebo);
//    SET_CMD_HANDLER(edi);
//    SET_CMD_HANDLER(sgt);
//    SET_CMD_HANDLER(seg);
//    SET_CMD_HANDLER(smg);
//    SET_CMD_HANDLER(suc);
//    SET_CMD_HANDLER(sbp);
 
#undef SET_HANDLER
}

void world_dtor(t_world * self)
{
    (void)self;
    std::cout << "world_dtor" << std::endl;
    delete self->data;
}

static t_world* _init_handler(void* world, t_data_class_type handlerClass)
{
    t_world * self = static_cast<t_world *>(world);
    
    self->data->game_element_type = handlerClass;
    return self;
}


/* HANDLERS C */

void	world_connected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = _init_handler(world, ENGINE_CLASS);
    self->data->engine_handler_ptr = &IEngine::connectedHandler;

    self->cpp_world->push_callback(self->data);    
}
void	world_disconnected_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = _init_handler(world, ENGINE_CLASS);
    self->data->engine_handler_ptr = &IEngine::disconnectedHandler;    

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
void	world_after_select_data(__attribute__((unused)) t_zc *zc, void *world)
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
    t_world * self = _init_handler(world, ENGINE_CLASS);
    self->data->engine_handler_ptr = &IEngine::errnoHandler;

    self->data->infos->err = err;
    self->data->infos->msg = msg;
    
    self->cpp_world->push_callback(self->data);    
}

void	world_msz_handler(__attribute__((unused)) t_zc *zc, t_msz *msz, void *world)
{
    t_world * self = _init_handler(world, MAP_VIEWER_CLASS);
    self->data->mapviewer_handler_ptr = &MapViewer::mapSizeHandler;
    
    self->data->infos->pos.first = msz->width;
    self->data->infos->pos.second = msz->height;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_bct_handler(__attribute__((unused)) t_zc *zc, t_bct *bct, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
    self->data->case_handler_ptr = &CaseObject::caseContentHandler;
    
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
    t_world * self = _init_handler(world, TEAM_MANAGER_CLASS);
    self->data->teammanager_handler_ptr = &TeamManager::teamNameHandler;
    
    self->data->infos->team_name = team_name;
    
    self->cpp_world->push_callback(self->data);
}
void    world_pnw_handler(__attribute__((unused)) t_zc *zc, t_pnw *pnw, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
    self->data->case_handler_ptr = &CaseObject::playerConnectionHandler;
    
    self->data->infos->player_id = pnw->uid;
    self->data->infos->pos.first = pnw->position.x;
    self->data->infos->pos.second = pnw->position.y;
    self->data->infos->orientation = static_cast<Orientation>(pnw->orientation);
    self->data->infos->level = pnw->level;
    self->data->infos->team_name = pnw->team_name;
    
    self->cpp_world->push_callback(self->data);    

    self->data->game_element_type = TEAM_MANAGER_CLASS;
    self->data->teammanager_handler_ptr = &TeamManager::playerConnectionHandler;
    self->cpp_world->push_callback(self->data);    
}
void    world_ppo_handler(__attribute__((unused)) t_zc *zc, t_ppo *ppo, void *world)
{
    t_world * self = _init_handler(world, MAP_OBJECT_CLASS);
    self->data->mapobject_handler_ptr = &MapObject::playerPositionHandler;
    
    self->data->infos->player_id = ppo->uid;
    self->data->infos->pos.first = ppo->position.x;
    self->data->infos->pos.second = ppo->position.y;
    
    self->cpp_world->push_callback(self->data);    
}
void	world_plv_handler(__attribute__((unused)) t_zc *zc, t_plv *plv, void *world)
{
    t_world * self = _init_handler(world, PLAYER_CLASS);
    self->data->player_handler_ptr = &PlayerObject::levelHandler;
    
    self->data->infos->player_id = plv->uid;
    self->data->infos->level = plv->level;
    
    self->cpp_world->push_callback(self->data);
}

void	world_pin_handler(__attribute__((unused)) t_zc *zc, t_pin *pin, void *world)
{
    t_world * self = _init_handler(world, PLAYER_CLASS);
    self->data->player_handler_ptr = &PlayerObject::inventoryHandler;

    self->data->infos->player_id = pin->uid;
    self->data->infos->pos.first = pin->position.x;
    self->data->infos->pos.second = pin->position.y;
    self->data->infos->quantity[static_cast<int>(FOOD)] = pin->items.food;
    self->data->infos->quantity[static_cast<int>(DERAUMERE)] = pin->items.deraumere;
    self->data->infos->quantity[static_cast<int>(LINEMATE)] = pin->items.linemate;
    self->data->infos->quantity[static_cast<int>(MENDIANE)] = pin->items.mendiane;
    self->data->infos->quantity[static_cast<int>(PHIRAS)] = pin->items.phiras;
    self->data->infos->quantity[static_cast<int>(SIBUR)] = pin->items.sibur;
    self->data->infos->quantity[static_cast<int>(THYSTAME)] = pin->items.thystame;

    self->cpp_world->push_callback(self->data);    
}
//void	world_pex_handler(__attribute__((unused)) t_zc *zc, unsigned int uid, void *world)
//{
//    t_world * self = _init_handler(world, PLAYER_CLASS);
//    self->data->player_handler_ptr = &PlayerObject::expelHandler;
//
//    // joueur expulsé (animation d'un coup de pied ? :p)
//
//    self->cpp_world->push_callback(self->data); 
//}
//void	world_pbc_handler(__attribute__((unused)) t_zc *zc, t_pbc *pbc, void *world)
//{
//    t_world * self = _init_handler(world, CASE_CLASS);
//    self->data->player_handler_ptr = &CaseObject::broadcastHandler;
//
//    // broadcast d'un joeur (une petite bulle comme les bande dessiné en haut de sa tête ?)
//    self->data->infos->player_id = pbc->uid;
//    // char * pbc->message => Message du broadcast (souvent chiffré)
//
//    self->cpp_world->push_callback(self->data); 
//}
//void	world_pic_handler(__attribute__((unused)) t_zc *zc, t_pic *pic, void *world)
//{
//    t_world * self = _init_handler(world, PLAYER_CLASS);
//    self->data->player_handler_ptr = &CaseObject::invocationBeginHandler;
//
//    // Incantation du premier joueur pour les autres joueurs de la liste
//    // pic->nb_uids => le nombre de joueurs concernés pas l'incantation
//    // pic->uids[0] => uid du joueur qui lance l'incantation
//    self->data->infos->player_id = pic->uid;
//    self->data->infos->pos.first = pic->position.x;
//    self->data->infos->pos.second = pic->position.y;
//
//    self->cpp_world->push_callback(self->data); 
//}
//void	world_pie_handler(__attribute__((unused)) t_zc *zc, t_pie *pie, void *world)
//{
//    t_world * self = _init_handler(world, PLAYER_CLASS);
//    self->data->player_handler_ptr = &PlayerObject::invocationEndHandler;
//
//    // Fin de l'incantation
//    // si pie->result == true => Incantation réussie, sinon non
//    self->data->infos->player_id = pie->uid;
//    // bool pie->result => Réussite ou non de l'incantation
//
//    self->cpp_world->push_callback(self->data); 
//}
//void	world_pfk_handler(__attribute__((unused)) t_zc *zc, unsigned int uid, void *world)
//{
//    t_world * self = _init_handler(world, PLAYER_CLASS);
//    self->data->player_handler_ptr = &PlayerObject::forkHandler;
//
//    // le joueur COMMENCE à chier un oeuf ! YOSHI!
//    self->data->infos->player_id = uid;
//
//    self->cpp_world->push_callback(self->data); 
//}
//void	world_pdr_handler(__attribute__((unused)) t_zc *zc, t_pdr *pdr, void *world)
//{
//    t_world * self = _init_handler(world, PLAYER_CLASS);
//    self->data->player_handler_ptr = &PlayerObject::throwHandler;
//
//    // Le joeur jete une ressource
//    self->data->infos->player_id = pdr->uid;
//    self->data->infos->quantity[static_cast<int>(FOOD)] = pdr->resource == RESOURCE_FOOD ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(DERAUMERE)] = pdr->resource == RESOURCE_DERAUMERE ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(LINEMATE)] = pdr->resource == RESOURCE_LINEMATE ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(MENDIANE)] = pdr->resource == RESOURCE_MENDIANE ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(PHIRAS)] = pdr->resource == RESOURCE_PHIRAS ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(SIBUR)] = pdr->resource == RESOURCE_SIBUR ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(THYSTAME)] = pdr->resource == RESOURCE_THYSTAME ? 1 : 0;
//
//    self->cpp_world->push_callback(self->data); 
//}
//void	world_pgt_handler(__attribute__((unused)) t_zc *zc, t_pin *pin, void *world)
//{
//    t_world * self = _init_handler(world, PLAYER_CLASS);
//    self->data->player_handler_ptr = &PlayerObject::takeHandler;
//
//    // Le joueur prend une ressource
//    self->data->infos->player_id = pgt->uid;
//    self->data->infos->quantity[static_cast<int>(FOOD)] = pgt->resource == RESOURCE_FOOD ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(DERAUMERE)] = pgt->resource == RESOURCE_DERAUMERE ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(LINEMATE)] = pgt->resource == RESOURCE_LINEMATE ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(MENDIANE)] = pgt->resource == RESOURCE_MENDIANE ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(PHIRAS)] = pgt->resource == RESOURCE_PHIRAS ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(SIBUR)] = pgt->resource == RESOURCE_SIBUR ? 1 : 0;
//    self->data->infos->quantity[static_cast<int>(THYSTAME)] = pgt->resource == RESOURCE_THYSTAME ? 1 : 0;
//
//
//    self->cpp_world->push_callback(self->data); 
//}
void	world_pdi_handler(__attribute__((unused)) t_zc *zc, unsigned int uid, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
    self->data->case_handler_ptr = &CaseObject::playerDeathHandler;

    // Le joueur est mort
    self->data->infos->player_id = uid;

    self->cpp_world->push_callback(self->data); 

    self->data->game_element_type = TEAM_MANAGER_CLASS;
    self->data->teammanager_handler_ptr = &TeamManager::playerDeathHandler;
    self->cpp_world->push_callback(self->data);    
}
void    world_enw_handler(__attribute__((unused)) t_zc *zc, t_enw *enw, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
    self->data->case_handler_ptr = &CaseObject::eggHandler;

    // Le joeur a affranchi un noir dans une case
    self->data->infos->egg_id = enw->eid;
    self->data->infos->player_id = enw->uid;
    self->data->infos->pos.first = enw->position.x;
    self->data->infos->pos.second = enw->position.y;

    self->cpp_world->push_callback(self->data); 

    self->data->game_element_type = TEAM_MANAGER_CLASS;
    self->data->teammanager_handler_ptr = &TeamManager::eggHandler;
    self->cpp_world->push_callback(self->data);    
}
void    world_eht_handler(__attribute__((unused)) t_zc *zc, unsigned int eid, void *world)
{
    t_world * self = _init_handler(world, EGG_CLASS);
    self->data->egg_handler_ptr = &EggObject::hatchHandler;

    // L'oeuf a éclot
    self->data->infos->egg_id = eid;

    self->cpp_world->push_callback(self->data); 
}
void    world_ebo_handler(__attribute__((unused)) t_zc *zc, unsigned int eid, void *world)
{
    t_world * self = _init_handler(world, EGG_CLASS);
    self->data->egg_handler_ptr = &EggObject::connectedHandler;

    // Un joeur s'est connecté sur l'oeuf (on peut effacer l'oeuf)
    self->data->infos->egg_id = eid;

    self->cpp_world->push_callback(self->data); 
}
void    world_edi_handler(__attribute__((unused)) t_zc *zc, unsigned int eid, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
    self->data->case_handler_ptr = &CaseObject::eggDeathHandler;

    // L'oeuf est mort (on peut l'effacer)
    self->data->infos->egg_id = eid;

    self->cpp_world->push_callback(self->data); 

    self->data->game_element_type = TEAM_MANAGER_CLASS;
    self->data->teammanager_handler_ptr = &TeamManager::eggDeathHandler;
    self->cpp_world->push_callback(self->data);    
}

//TODO : celles qui sont en dessous !
void    world_sgt_handler(__attribute__((unused)) t_zc *zc, unsigned int time, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
//    self->data->player_handler_ptr = &CaseObject::playerPositionHandler;

    // Réucpération du T du serveur... à quoi ça peut bien te servir ??
    self->data->infos->time_unit = time;

    self->cpp_world->push_callback(self->data); 
}
void    world_seg_handler(__attribute__((unused)) t_zc *zc, const char *team_name, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
//    self->data->player_handler_ptr = &CaseObject::playerPositionHandler;

    // fin du jeu
    self->data->infos->team_name = team_name;

    self->cpp_world->push_callback(self->data); 
}
void    world_suc_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
//    self->data->player_handler_ptr = &CaseObject::playerPositionHandler;

    // commande non connue

    self->cpp_world->push_callback(self->data); 
}
void    world_sbp_handler(__attribute__((unused)) t_zc *zc, void *world)
{
    t_world * self = _init_handler(world, CASE_CLASS);
//    self->data->player_handler_ptr = &CaseObject::playerPositionHandler;

    // commande bad param

    self->cpp_world->push_callback(self->data); 
}