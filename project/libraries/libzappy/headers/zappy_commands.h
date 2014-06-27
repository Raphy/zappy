/*
** zappy_commands.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Fri Jun 27 19:43:18 2014 raphael defreitas
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

#endif /* !ZAPPY_COMMANDS_H_*/
