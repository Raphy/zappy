/*
** handlers.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:39:18 2014 raphael defreitas
** Last update Fri Jun 27 19:46:03 2014 raphael defreitas
*/

#ifndef		HANDLERS_H_
# define	HANDLERS_H_

# include	"zappy.h"

/*
** Server handlers
*/
void		set_server_handlers(t_zs *, void *);
void		errno_handler(t_zs *, int, const char *, void *);
void		callback_handler(t_zs *, t_zht, void *);
void		timeout_handler(t_zs *, void *);
void		client_connected_handler(t_zs *, t_zc *, void *);
void		client_disconnected_handler(t_zs *, t_zc *, void *);

#endif /* !HANDLERS_H_*/
