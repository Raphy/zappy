/* 
 * File:   Worker.hh
 * Author: marie
 *
 * Created on July 3, 2014, 6:37 PM
 */

#ifndef WORKER_HH
#define	WORKER_HH

#include    "Thread.hh"
#include    "ISafeQueue.hh"
#include    "cWorld.hh"

// classe concernée par le changement
// donc le real_ptr sera appelé depuis sa classe parent
typedef enum s_handler_class_type
{
    MAP_CLASS,
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
    ERRNO_EVENT,
    MAP_SIZE_EVENT,
    CASE_CONTENT_EVENT,
    EVENT_COUNT,
    //...
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

class World;

typedef struct s_world
{
    World *	cpp_world;
    //    void *	callptr;
    t_data *	data;
} t_world;

void world_ctor(t_world * self, World * cpp_world);
void world_dtor(t_world * self);
void world_loop(t_world * self);// au final ne fera que appeler zappy_main

class World : public Thread
{
public:
    World(ISafeQueue<t_data *> * eventQueue, ISafeQueue<t_data *> * commandQueue);
    virtual ~World();
    
    void *	routine();
    
    void	push_callback(t_data * data);    
    t_data *	pop_command();

    t_zc *	getZc() { return &_zc; }
    
private:
    ISafeQueue<t_data *> *	_eventQueue;
    ISafeQueue<t_data *> *	_commandQueue;
    t_world		_world;
    t_zc		_zc;
};

#endif	/* WORKER_HH */

