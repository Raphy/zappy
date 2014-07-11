/*
** handlers.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:39:18 2014 raphael defreitas
** Last update Fri Jul 11 17:49:31 2014 damien sauvalle
*/

#ifndef		HANDLERS_H_
# define	HANDLERS_H_

# include	"zappy.h"
# include       "server.h"

/*
** Server handlers
*/
void            handler_before_select(t_zs *, void *);
void            handler_after_select(t_zs *, void *);
void		set_server_handlers(t_zs *, t_server *);
void		errno_handler(t_zs *, int, const char *, void *);
void		callback_handler(t_zs *, t_zht, void *);
void		timeout_handler(t_zs *, void *);
void		client_connected_handler(t_zs *, t_zc *, t_server *);
void		client_disconnected_handler(t_zs *, t_zc *, void *);

/*
** Client handlers
*/
void		set_client_handlers(t_zc *, void *);
void		cmd_unknown_handler(t_zs *, t_zc *, const char *, void *);

void		cmd_team_name_handler(t_zs *, t_zc *, const char *, t_server *);

void		cmd_graphic_handler(t_zs *, t_zc *, void *);

void		cmd_rmt_handler(t_zs *, t_zc *, void *);
void		rmt_pubkey_handler(t_zs *, t_zc *, const char *, void *);
void		rmt_stop_handler(t_zs *, t_zc *, void *);
void		rmt_teams_handler(t_zs *, t_zc *, void *);

#endif /* !HANDLERS_H_*/
