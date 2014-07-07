/* 
 * File:   cWorker.hh
 * Author: marie
 *
 * Created on July 3, 2014, 6:44 PM
 */

#ifndef CWORKER_HH
#define	CWORKER_HH

#include    <glib.h>

extern "C" {
#include    "zappy.h"
}

//typedef	void	(t_zsh_basic)(t_zs *zs, void *data);
//
//typedef	void	(t_zsh_client_basic)(t_zs *zs, t_zc *zc, void *data);
//
//typedef	void	(t_zsh_str_basic)(t_zs *zs, t_zc *zc, const char *str, void *d);


G_BEGIN_DECLS

//typedef	void	(t_zch_cmd_msz)(t_zc *zc, t_msz msz, void *d);
//void		zc_hook_cmd_msz(t_zc *, t_zch_cmd_msz h, void *d);

void	world_basic_handler(void *data); // doit respecter typedef handler zappy
void	world_level_handler(void *data, int level); // doit respecter typedef handler zappy
void	world_msz_handler(t_zc *zc, t_msz *msz, void *world); // doit respecter typedef handler zappy
void	world_errno_handler(t_zc *zc, int err, const char *msg, void *world);
void	world_connected_handler(t_zc *zc, void *world);

G_END_DECLS

//void world_ctor();
//
//void world_dtor();
//
//// au final ne fera que appeler zappy_main
//void world_loop();

#endif	/* CWORKER_HH */

