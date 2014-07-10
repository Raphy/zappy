/* 
 * File:   cWorker.hh
 * Author: marie
 *
 * Created on July 3, 2014, 6:44 PM
 */

#ifndef CWORLD_HH
#define	CWORLD_HH

#include    <glib.h>
#include    <utility>
#include    <string>
#include    <vector>
#include    "enums.hh"

extern "C" {
#include    "zappy.h"
}


// ** register handler in world_ctor:
//    zc_hook_cmd_msz(cpp_world->getZc(), &world_msz_handler, self);
//
// ** declare handler in cWorld.hh:
//void	world_msz_handler(t_zc *zc, t_msz *msz, void *world);
//
// ** implement it in cWorld.cpp:
//void	world_msz_handler(__attribute__((unused)) t_zc *zc, t_msz *msz, void *world)
//{
//    t_world * self = static_cast<t_world *>(world); //get self
//    
//    self->data->event_type = MAP_SIZE_EVENT; //set type of event and concerned element
//    self->data->game_element_type = MAP_CLASS;
//    
//    self->data->infos->pos.first = msz->width; //set utils informations
//    self->data->infos->pos.second = msz->height;
//    
//    self->cpp_world->push_callback(self->data); //push the data for the other thread
//}
//
// ** call the right handler in the other thread :
//   case MAP_SIZE_EVENT:
//    _mapViewer->createGround(data->infos->pos.first, data->infos->pos.second);
//    break;
//
// ** implement it in the right object
//bool MapViewer::createGround(int x, int y)
//{
//    if (!_cameraManager.init(x, y)
//	    || !_mapObject->createGround(x, y))
//	return false;
//    return _cameraManager.addCollision(_mapObject->getSelector());
//}



class World;

// classe concernée par le changement
// donc le real_ptr sera appelé depuis sa classe parent
typedef enum s_handler_class_type
{
    MAP_CLASS = 0,
    ENGINE_CLASS,
    PERSO_CLASS,
    EGG_CLASS,
    RESSOURCE_CLASS,
    TEAM_MANAGER_CLASS,
    HANDLER_CLASS_COUNT,
} t_handler_class_type;

// defini le type du handler pour caster le pointeur sur fonction
//typedef enum s_handler_ptr_type
//{
//    BASIC_HANDLER,
//    INT_HANDLER,
//    MSG_HANDLER,
//    //...
//} t_handler_ptr_type;F

typedef enum s_event_type
{
    CONNECTED_EVENT = 0,
    DISCONNECTED_EVENT,
    GAME_END_EVENT,
    ERRNO_EVENT,
    MSG_EVENT,

    TIME_EVENT,
    MAP_SIZE_EVENT,
    CASE_CONTENT_EVENT,
    TEAM_NAME_EVENT,

    PERSO_CONNECTION_EVENT,
    PERSO_DEAD_EVENT,
    PERSO_POSITION_EVENT,
    PERSO_LEVEL_EVENT,
    PERSO_INVENTORY_EVENT,
    PERSO_EXPEL_EVENT,
    PERSO_BROADCAST_EVENT,

    INVOCATION_BEGIN_EVENT,
    INVOCATION_END_EVENT,	    
    THROW_RESSOURCE_EVENT,
    TAKE_RESSOURCE_EVENT,
	    
    EGG_LAYED_BEGIN_EVENT,
    EGG_LAYED_END_EVENT,
    EGG_HATCH_EVENT,
    EGG_TAKEN_EVENT,
    EGG_DEAD_EVENT,

    MAP_SIZE_COMMAND,
    CASE_CONTENT_COMMAND,
    MAP_CONTENT_COMMAND,
    TEAM_NAME_COMMAND,
    PERSO_POSITION_COMMAND,
    PERSO_LEVEL_COMMAND,
    PERSO_INVENTORY_COMMAND,
    TIME_GET_COMMAND,
    TIME_SET_COMMAND,

    EVENT_COUNT,
} t_event_type;

typedef struct s_infos
{
//    int	    x;
//    int	    y;
    std::pair<int,int>	pos;
    Orientation	    orientation;
    int	    level;
    std::vector<int>	    quantity;
    int	    player_id;//list ?
    int	    egg_id;
    int	    ressource_id;
    int	    time_unit;
    std::string  team_name;
    int	    err;
    std::string  msg;    
//    const char *  msg;    
} t_infos;

typedef struct s_data
{
    t_handler_class_type	game_element_type;
    t_event_type		event_type;
//    t_handler_ptr_type		ptr_type;
//    bool	(*realptr)(t_infos*);//?
    t_infos *	infos;
} t_data;


G_BEGIN_DECLS
	
typedef struct s_world
{
    World *	cpp_world;
    //    void *	callptr;
    t_data *	data;
} t_world;

//void	world_basic_handler(void *data);
//void	world_level_handler(void *data, int level);

void	world_connected_handler(t_zc *zc, void *world);
void	world_disconnected_handler(t_zc *zc, void *world);
void	world_before_select_handler(t_zc *zc, void *world);
void	world_after_select_handler(t_zc *zc, void *world);

void	world_stdin_handler(t_zc *zc, void *world);
void	world_cmd_unknow_handler(t_zc *zc, void *world);
void	world_cmd_welcome_handler(t_zc *zc, void *world);
void	world_ok_handler(t_zc *zc, void *world);
void	world_ko_handler(t_zc *zc, void *world);
void	world_errno_handler(t_zc *zc, int err, const char *msg, void *world);

void	world_msz_handler(t_zc *zc, t_msz *msz, void *world);
void	world_bct_handler(t_zc *zc, t_bct *bct, void *world);
void	world_tna_handler(t_zc *zc, const char *team_name, void *world);

G_END_DECLS

#endif	/* CWORLD_HH */

