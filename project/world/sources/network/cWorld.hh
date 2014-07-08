/* 
 * File:   cWorker.hh
 * Author: marie
 *
 * Created on July 3, 2014, 6:44 PM
 */

#ifndef CWORLD_HH
#define	CWORLD_HH

#include    <glib.h>

extern "C" {
#include    "zappy.h"
}

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
    HANDLER_CLASS_COUNT,
} t_handler_class_type;

// defini le type du handler pour caster le pointeur sur fonction
//typedef enum s_handler_ptr_type
//{
//    BASIC_HANDLER,
//    INT_HANDLER,
//    MSG_HANDLER,
//    //...
//} t_handler_ptr_type;

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
    TEAM_NAME_COMMAND,
    PLAYER_POSITION_COMMAND,
    PLAYER_LEVEL_COMMAND,
    PLAYER_INVENTORY_COMMAND,
    TIME_GET_COMMAND,
    TIME_SET_COMMAND,

    EVENT_COUNT,
} t_event_type;

typedef struct s_infos
{
    int	    x;
    int	    y;
    int	    orientation;
    int	    level;
    int	    quantity;
    int	    player_id;//list ?
    int	    egg_id;
    int	    ressource_id;
    int	    time_unit;
    char *  team_name;
    int	    err;
    const char *  msg;    
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

void	world_basic_handler(void *data);
void	world_level_handler(void *data, int level);
void	world_msz_handler(t_zc *zc, t_msz *msz, void *world);
void	world_errno_handler(t_zc *zc, int err, const char *msg, void *world);
void	world_connected_handler(t_zc *zc, void *world);

G_END_DECLS

#endif	/* CWORLD_HH */

