/*
** zappy_commands.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Sat Jul  5 15:45:15 2014 raphael defreitas
*/

#ifndef		ZAPPY_COMMANDS_H_
# define	ZAPPY_COMMANDS_H_

/*
** +----------+
** | Required |
** +----------+
*/

# include	<glib.h>

/*
** +--------+
** | Server |
** +--------+
*/

/*
** Sends "BIENVENUE\n" to a specific client.
** zc		The client. If NULL sends to all clients.
*/
void		zs_send_welcome(t_zs *, t_zc *zc);

/*
** Sends the pubkey to a specific client.
** zc		The client. If NULL sends to all clients.
*/
void		zs_send_rmt_pubkey(t_zs *, t_zc *zc);

void		zs_send_rmt_authorized(t_zs *, t_zc *zc);
void		zs_send_rmt_unauthorized(t_zs *, t_zc *zc);

/*
** +--------+
** | Client |
** +--------+
*/

/*
** Sends "TEAM_NAME\n" to server.
** team_name	The team name to send.
*/
void		zc_send_team_name(t_zc *, const char *team_name);

void		zc_send_graphic(t_zc *);

void		zc_send_rmt(t_zc *);

void		zc_send_rmt_pubkey(t_zc *);

void		zc_send_rmt_stop(t_zc *);

void		zc_send_rmt_teams(t_zc *);

void		zc_send_cmd_forward(t_zc *);
void		zc_send_cmd_left(t_zc *);
void		zc_send_cmd_right(t_zc *);

#endif /* !ZAPPY_COMMANDS_H_*/
