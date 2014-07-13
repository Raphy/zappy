/*
** player_action.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 01:25:17 2014 damien sauvalle
** Last update Sun Jul 13 11:01:08 2014 damien sauvalle
*/

#ifndef		PLAYER_ACTION_H_
# define	PLAYER_ACTION_H_

# include	"server.h"
# include	"player.h"
# include	"bundle.h"

void		add_player(t_server *, t_player *);
void		server_send_ppo_all_graphic(t_bundle *);
void		player_action_goahead(t_zc *, void *);
void		player_action_right(t_zc *, void *);
void		player_action_left(t_zc *, void *);
void		player_action_see(t_player *, void *);
void		player_action_inventory(t_player *, void *);
void		player_action_pick(t_player *, void *);
void		player_action_put(t_player *, void *);
void		player_action_expel(t_player *, void *);
void		player_action_broacast(t_player *, void *);
void		player_action_incantation(t_zc *, void *);
void		player_action_fork(t_player *, void *);
void		player_action_slot_number(t_player *, void *);

typedef void	(*fct_direction)(t_bundle *);

#endif
