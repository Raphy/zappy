/* 
 * File:   cWorker.hh
 * Author: marie
 *
 * Created on July 3, 2014, 6:44 PM
 */

#ifndef CWORKER_HH
#define	CWORKER_HH

#include    <glib.h>

//typedef	void	(t_zsh_basic)(t_zs *zs, void *data);
//
//typedef	void	(t_zsh_client_basic)(t_zs *zs, t_zc *zc, void *data);
//
//typedef	void	(t_zsh_str_basic)(t_zs *zs, t_zc *zc, const char *str, void *d);


G_BEGIN_DECLS

void worker_basic_callback(void *data); // doit respecter typedef callback zappy
void worker_level_callback(void *data, int level); // doit respecter typedef callback zappy

G_END_DECLS

//void worker_ctor();
//
//void worker_dtor();
//
//// au final ne fera que appeler zappy_main
//void worker_loop();

#endif	/* CWORKER_HH */

