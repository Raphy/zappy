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
#include    "cWorker.hh"

// classe concernée par le changement
// donc le real_ptr sera appelé depuis sa classe parent
typedef enum s_handler_class_type
{
    MAP_CLASS,
    ENGINE_CLASS,
    PERSO_CLASS,
    EGG_CLASS,
    RESSOURCE_CLASS,
} t_handler_class_type;

//// defini le type du handler pour caster le pointeur sur fonction
//typedef enum s_handler_ptr_type
//{
//    BASIC_HANDLER,
//    INT_HANDLER,
//    MSG_HANDLER,
//    //...
//} t_handler_ptr_type;

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
    char *  msg;    
} t_infos;

typedef struct s_data
{
    t_handler_class_type	game_element_type;
//    t_handler_ptr_type		ptr_type;
    bool	(*realptr)(t_infos*);//?
    t_infos *	infos;
} t_data;

class Worker;

typedef struct s_worker
{
    Worker *	cpp_worker;
//    void *	callptr;
    t_data *	data;
} t_worker;

void worker_ctor(t_worker * self, Worker * cpp_worker);
void worker_dtor(t_worker * self);
void worker_loop(t_worker * self);// au final ne fera que appeler zappy_main

class Worker : public Thread
{
public:
    Worker(ISafeQueue<t_data *> * eventQueue, ISafeQueue<t_data *> * commandQueue)
    : _eventQueue(eventQueue), _commandQueue(commandQueue)
    {
	worker_ctor(&_worker, this);
    }
    virtual ~Worker()
    {
	worker_dtor(&_worker);
    }
    
    void *	routine()
    {
	worker_loop(&_worker);
	return nullptr;
    }

    void push_callback(t_data * data)
    {
	_eventQueue->push(data);
    }

    t_data * pop_command()
    {
//	t_data command_data;
//	_commandQueue->tryPop(&command_data);
	return nullptr;
    }

private:
    ISafeQueue<t_data *> *	_eventQueue;
    ISafeQueue<t_data *> *	_commandQueue;
    t_worker		_worker;
};

#endif	/* WORKER_HH */

