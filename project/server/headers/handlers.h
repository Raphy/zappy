/*
** handlers.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:39:18 2014 raphael defreitas
** Last update Sun Jul 13 10:59:32 2014 damien sauvalle
*/

#ifndef		HANDLERS_H_
# define	HANDLERS_H_

# include	"zappy.h"
# include	"server.h"
# include	"player.h"

/*
** Server handlers
*/
void		handler_before_select(t_zs *, void *);
void		handler_after_select(t_zs *, void *);
void		handler_forward(t_zs *, t_zc *, void *);
void		handler_left(t_zs *, t_zc *, void *);
void		handler_right(t_zs *, t_zc *, void *);
void		handler_see(t_zs *, t_zc *, void *);
void		handler_inventory(t_zs *, t_zc *, void *);
void		handler_pick(t_zs *, t_zc *, void *);
void		handler_put(t_zs *, t_zc *, void *);
void		handler_expel(t_zs *, t_zc *, void *);
void		handler_broadcast(t_zs *, t_zc *, const char *, void *);
void		handler_incantation(t_zs *, t_zc *, void *);
void		handler_fork(t_zs *, t_zc *, void *);
void		handler_slot_number(t_zs *, t_zc *, void *);
void		set_server_handlers(t_zs *, t_server *);
void		errno_handler(t_zs *, int, const char *, void *);
void		callback_handler(t_zs *, t_zht, void *);
void		timeout_handler(t_zs *, void *);
void		client_connected_handler(t_zs *, t_zc *, void *);
void		client_disconnected_handler(t_zs *, t_zc *, void *);

/*
** Client handlers
*/
void		set_client_handlers(t_zc *, void *);
void		cmd_unknown_handler(t_zs *, t_zc *, const char *, void *);
void		cmd_team_name_handler(t_zs *, t_zc *, const char *, void *);
void		cmd_graphic_handler(t_zs *, t_zc *, void *);
void		cmd_rmt_handler(t_zs *, t_zc *, void *);
void		rmt_pubkey_handler(t_zs *, t_zc *, const char *, void *);
void		rmt_stop_handler(t_zs *, t_zc *, void *);
void		rmt_teams_handler(t_zs *, t_zc *, void *);

 /*
 ** Handler extra functions
 */

int		verify_elevation_condition(t_player *, t_case *);

#endif	/* !HANDLERS_H_ */
