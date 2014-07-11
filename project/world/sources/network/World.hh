/* 
 * File:   Worker.hh
 * Author: marie
 *
 * Created on July 3, 2014, 6:37 PM
 */

#ifndef WORLD_HH
#define	WORLD_HH

#include    "Thread.hh"
#include    "ISafeQueue.hh"
#include    "cWorld.hh"

class World;

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
    bool	try_pop_command(t_data * data);

    t_zc *	getZc() { return &_zc; }
    
private:
    ISafeQueue<t_data *> *	_eventQueue;
    ISafeQueue<t_data *> *	_commandQueue;
    t_world		_world;
    t_zc		_zc;
};

#endif	/* WORLD_HH */

