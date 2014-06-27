/*
** zappy_hooks.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Fri Jun 27 17:22:37 2014 raphael defreitas
*/

#ifndef		ZAPPY_HOOKS_H_
# define	ZAPPY_HOOKS_H_

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

typedef	void	(t_zsh_errno)(t_zs *zs, int err, const char *msg, void *data);
void		zs_hook_errno(t_zs *this, t_zsh_errno h, void *d);

typedef	void	(t_zsh_callback)(t_zs *zs, t_zht type, void *data);
void		zs_hook_callback(t_zs *this, t_zsh_callback h, void *d);

typedef	void	(*t_zsh_timeout)(t_zs *zs, void *data);
void		zs_hook_timeout(t_zs *this, t_zsh_timeout h, void *d);

typedef	void	(*t_zsh_client_connected)(t_zs *zs, t_zc *zc, void *data);
void		zs_hook_client_connected(t_zs *this, t_zsh_client_connected h,
					 void *d);

typedef	void	(*t_zsh_client_disconnected)(t_zs *zs, t_zc *zc, void *data);
void		zs_hook_client_disconnected(t_zs *this,
					    t_zsh_client_disconnected h,
					    void *d);

/*
** +--------+
** | Client |
** +--------+
*/

typedef	void	(t_zch_errno)(t_zc *zc, int err, const char *msg, void *data);
void		zc_hook_errno(t_zc *this, t_zch_errno h, void *d);

typedef	void	(t_zch_callback)(t_zc *zc, t_zht type, void *data);
void		zc_hook_callback(t_zc *this, t_zch_callback h, void *d);

typedef	void	(*t_zch_timeout)(t_zc *zc, void *data);
void		zc_hook_timeout(t_zc *this, t_zch_timeout h, void *d);

#endif /* !ZAPPY_HOOKS_H_*/
