/* 
 * File:   cWorker.cpp
 * Author: marie
 * 
 * Created on July 3, 2014, 6:44 PM
 */

#include <iostream>
#include <unistd.h>
#include    "Worker.hh"
#include "cWorker.hh"
#include "zappy.h"

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
    std::cout << "worker_dtor" << std::endl;
}

// au final ne fera que appeler zappy_main
void worker_loop(t_worker * self)
{
    while (42)
    {
	//do callback
        std::cout << "worker_loop" << std::endl;
	sleep(1);
    }
}


/* CALLBACKS C */

void worker_basic_callback(void *data) // doit respecter typedef callback zappy
{
    // rempli basique structure
    ((Worker *)((t_worker *)data)->cpp_worker)->push_callback(data);//push real_data ??
}

void worker_int_callback(void *data, int level) // doit respecter typedef callback zappy
{
    // rempli basique structure
   ((t_real_data *)(((t_worker *)data))->real_data)->level = level;
    ((Worker *)((t_worker *)data)->cpp_worker)->push_callback(data);
}
