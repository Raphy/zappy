/*
** _zappy.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 13:13:50 2014 raphael defreitas
** Last update Fri Jun 27 17:22:10 2014 raphael defreitas
*/

#ifndef		_ZAPPY_H_
# define	_ZAPPY_H_

/*
** +----------+
** | Required |
** +----------+
*/
# include	<glib.h>

#include	"zappy.h"

G_BEGIN_DECLS

/*
** +--------+
** | Server |
** +--------+
*/

void		zs_treat_fds(t_zs *);
void		zs_treat_zc(t_zs *, t_zc *);

/*
** Event managing
*/
void		zs_hook(t_zs *, t_zht, void (*)(), void *);
void		zs_handle_errno(t_zs *, const char *);
void		zs_handle_callback(t_zs *, t_zht);
void		zs_handle_timeout(t_zs *);
void		zs_handle_client_connected(t_zs *, t_zc *);
void		zs_handle_client_disconnected(t_zs *, t_zc *);

/*
** +--------+
** | Client |
** +--------+
*/

/*
** Event managing
*/
void		zc_hook(t_zc *, t_zht, void (*)(), void *);
void		zc_handle_errno(t_zc *, const char *);
void		zc_handle_callback(t_zc *, t_zht);
void		zc_handle_timeout(t_zc *);

G_END_DECLS

#endif /* !_ZAPPY_H_*/