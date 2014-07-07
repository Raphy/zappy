/* 
 * File:   cWorker.cpp
 * Author: marie
 * 
 * Created on July 3, 2014, 6:44 PM
 */

#include <iostream>
#include <unistd.h>
#include "Worker.hh"
#include "cWorker.hh"
#include "zappy.h"

#include "ILevel.hh"

//typedef	void	(t_zsh_basic)(t_zs *zs, void *data);
//
//typedef	void	(t_zsh_client_basic)(t_zs *zs, t_zc *zc, void *data);
//
//typedef	void	(t_zsh_str_basic)(t_zs *zs, t_zc *zc, const char *str, void *d);

void worker_ctor(t_worker * self, Worker * cpp_worker)
{
    std::cout << "worker_ctor" << std::endl;
    self->cpp_worker = cpp_worker;
    //set handlers
}

void worker_dtor(t_worker * self)
{
    (void)self;
    std::cout << "worker_dtor" << std::endl;
}

// au final ne fera que appeler zappy_main
void worker_loop(t_worker * self)
{
    (void)self;
    while (42)
    {
	//do callback
        std::cout << "worker_loop" << std::endl;
	sleep(1);
    }
}


/* CALLBACKS C */

void worker_basic_callback(void *worker) // doit respecter typedef callback zappy
{
    // rempli basique structure
    t_worker * self = static_cast<t_worker *>(worker);
    self->cpp_worker->push_callback(self->data);//push real_data ??
}

void worker_level_callback(void *worker, int level) // doit respecter typedef callback zappy
{
    t_worker * self = static_cast<t_worker *>(worker);

//    self->data->realptr = &ILevel::setLevel;
//    self->data->ptr_type = INT_HANDLER;
    self->data->game_element_type = PERSO_CLASS;

    self->data->infos->level = level;

    self->cpp_worker->push_callback(self->data);
}
