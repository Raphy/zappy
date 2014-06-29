/*
** zappy_commands.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Sun Jun 29 10:14:52 2014 raphael defreitas
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
void		zs_send_welcome(t_zs *this, t_zc *zc);

/*
** +--------+
** | Client |
** +--------+
*/

/*
** Sends "TEAM_NAME\n" to server.
** team_name	The team name to send.
*/
void		zc_send_team_name(t_zc *this, const char *team_name);
void		zc_send_graphic(t_zc *this);
void		zc_send_remote(t_zc *this);

#endif /* !ZAPPY_COMMANDS_H_*/
