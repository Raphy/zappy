/*
** _zappy.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 13:13:50 2014 raphael defreitas
** Last update Sun Jun 29 06:51:57 2014 raphael defreitas
*/

#ifndef		_ZAPPY_H_
# define	_ZAPPY_H_

/*
** +----------+
** | Required |
** +----------+
*/
# include	<glib.h>
# include	<stdbool.h>

#include	"zappy.h"

G_BEGIN_DECLS

/*
** +--------+
** | Server |
** +--------+
*/

void		zs_treat_fds(t_zs *);
void		zs_treat_zc(t_zs *, t_zc *);
void		zs_send(t_zs *, t_zc *, const char *);
void		zs_send_to_client(t_zs *, t_zc *, const char *);
void		zs_send_to_all(t_zs *, const char *);

/*
** Command dispatcher
*/
typedef	bool	(*t_zs_cmd)(t_zs *, t_zc *, const char *);
void		zs_dispatch_command(t_zs *, t_zc *, const char *);
bool		zs_cmd_team_name(t_zs *, t_zc *, const char *);

/*
** Event managing
*/
void		zs_hook(t_zs *, t_zht, void (*)(), void *);
void		zs_handle_errno(t_zs *, const char *);
void		zs_handle_callback(t_zs *, t_zht);
void		zs_handle_timeout(t_zs *);
void		zs_handle_client_connected(t_zs *, t_zc *);
void		zs_handle_client_disconnected(t_zs *, t_zc *);
void		zs_handle_cmd_unknown(t_zs *, t_zc *, const char *);
void		zs_handle_cmd_team_name(t_zs *, t_zc *, const char *);

/*
** +--------+
** | Client |
** +--------+
*/

void		zc_treat_fds(t_zc *);

/*
** Command dispatcher
*/
typedef	bool	(*t_zc_cmd)(t_zc *, const char *);
void		zc_dispatch_command(t_zc *, const char *);
bool		zc_cmd_welcome(t_zc *, const char *);

/*
** Event managing
*/
void		zc_hook(t_zc *, t_zht, void (*)(), void *);
void		zc_handle_errno(t_zc *, const char *);
void		zc_handle_callback(t_zc *, t_zht);
void		zc_handle_timeout(t_zc *);
void		zc_handle_connected(t_zc *);
void		zc_handle_disconnected(t_zc *);
void		zc_handle_cmd_unknown(t_zc *, const char *);
void		zc_handle_cmd_welcome(t_zc *);

/*
** +-------+
** | Tools |
** +-------+
*/
int		zt_build_command(t_list *, char **);
int		zt_append_buffer(t_list *, const char *);

G_END_DECLS

#endif /* !_ZAPPY_H_*/
