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
#include    <array>
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

typedef struct s_infos	t_infos;
typedef struct s_data	t_data;


// classe concernée par le changement
// donc le real_ptr sera appelé depuis sa classe parent
typedef enum s_data_class_type
{
    ENGINE_CLASS = 0,
    MAP_VIEWER_CLASS,
    MAP_OBJECT_CLASS,
    CASE_CLASS,
    PLAYER_CLASS,
    EGG_CLASS,
    RESSOURCE_CLASS,
    TEAM_MANAGER_CLASS,
    HANDLER_CLASS_COUNT,
} t_data_class_type;

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

    PLAYER_CONNECTION_EVENT,
    PLAYER_DEAD_EVENT,
    PLAYER_POSITION_EVENT,
    PLAYER_LEVEL_EVENT,
    PLAYER_INVENTORY_EVENT,
    PLAYER_EXPEL_EVENT,
    PLAYER_BROADCAST_EVENT,

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
    PLAYER_POSITION_COMMAND,
    PLAYER_LEVEL_COMMAND,
    PLAYER_INVENTORY_COMMAND,
    TIME_GET_COMMAND,
    TIME_SET_COMMAND,

    EVENT_TYPE_COUNT,
} t_event_type;

struct s_infos
{
    s_infos()
    {
	pos.first = -1;
	pos.second = -1;
	orientation = NORTH;
	level = -1;
	quantity.fill(-1);
	player_id = -1;//list ?
	egg_id = -1;
	ressource_id = -1;
	time_unit = -1;
	team_name = std::string("");
	err = -1;
	msg = std::string("");
    }
    std::pair<int,int>	pos;
    Orientation	    orientation;
    int	    level;
    std::array<int, RESSOURCE_TYPE_COUNT>	    quantity;
    int	    player_id;//list ?
    int	    egg_id;
    int	    ressource_id;
    int	    time_unit;
    std::string  team_name;
    int	    err;
    std::string  msg;
};

class IEngine;
class MapViewer;
class MapObject;
class PlayerObject;
class CaseObject;

typedef	bool (IEngine::*engine_handler_t)(t_infos *);
typedef	bool (MapViewer::*mapviewer_handler_t)(t_infos *);
typedef	bool (MapObject::*mapobject_handler_t)(t_infos *);
typedef	bool (CaseObject::*case_handler_t)(t_infos *);
typedef	bool (PlayerObject::*player_handler_t)(t_infos *);

struct s_data
{
    s_data()
    {
	game_element_type = HANDLER_CLASS_COUNT;
//	event_type = EVENT_TYPE_COUNT;
	infos = new t_infos();
    }
    s_data(s_data const& orig)
    {
	game_element_type = orig.game_element_type;
//	event_type = orig.event_type;
	infos = new t_infos(*(orig.infos));
    }
    ~s_data()
    {
	delete infos;
    }
    
    t_data_class_type	game_element_type;
//    t_event_type		event_type;

    engine_handler_t		engine_handler_ptr;
    mapviewer_handler_t		mapviewer_handler_ptr;
    mapobject_handler_t		mapobject_handler_ptr;
    case_handler_t		case_handler_ptr;
    player_handler_t		player_handler_ptr;
    t_infos *	infos;
};


G_BEGIN_DECLS
	
typedef struct s_world
{
    World *	cpp_world;
    //    void *	callptr;
    t_data *	data;
} t_world;

void	world_connected_handler(t_zc *zc, void *world);
void	world_disconnected_handler(t_zc *zc, void *world);
void	world_before_select_data(t_zc *zc, void *world);
void	world_after_select_data(t_zc *zc, void *world);

void	world_stdin_handler(t_zc *zc, void *world);
void	world_cmd_unknow_handler(t_zc *zc, void *world);
void	world_cmd_welcome_handler(t_zc *zc, void *world);
void	world_ok_handler(t_zc *zc, void *world);
void	world_ko_handler(t_zc *zc, void *world);
void	world_errno_handler(t_zc *zc, int err, const char *msg, void *world);

void	world_msz_handler(t_zc *zc, t_msz *msz, void *world);
void	world_bct_handler(t_zc *zc, t_bct *bct, void *world);
void	world_tna_handler(t_zc *zc, const char *team_name, void *world);
void	world_plv_handler(t_zc *zc, t_plv *plv, void *world);

G_END_DECLS

#endif	/* CWORLD_HH */

