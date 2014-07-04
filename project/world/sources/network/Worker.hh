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

typedef struct s_worker
{
    void *  cpp_worker;
    void *  callptr;
    void *  real_data;
} t_worker;

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

typedef struct s_real_data
{
    t_handler_class_type	game_element_type;
    void *  realptr;
    
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
} t_real_data;

class Worker;

void worker_ctor(t_worker * self, Worker * cpp_worker);
void worker_dtor(t_worker * self);
void worker_loop(t_worker * self);// au final ne fera que appeler zappy_main

class Worker : public Thread
{
public:
    Worker()
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

    void push_callback(void *data)
    {
	_eventQueue->push(data);
    }

private:
    ISafeQueue<void*> *	_eventQueue;
    t_worker		_worker;
};

#endif	/* WORKER_HH */

