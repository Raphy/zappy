/*
** remote.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Sun Jun 29 18:38:50 2014 raphael defreitas
** Last update Tue Jul  1 04:48:16 2014 raphael defreitas
*/

#ifndef		REMOTE_H_
# define	REMOTE_H_

#include	"zappy.h"

typedef	struct
{
  t_zc		*zc;
}		t_remote;

int		remote_ctor(t_remote *this, t_zc *zc);
void		remote_dtor(t_remote *this);

void		remote_set_handlers(t_remote *this);

void		remote_errno_handler(t_zc *, int , const char *, void *);
void		remote_connected_handler(t_zc *, void *);
void		remote_disconnected_handler(t_zc *, void *);
void		remote_callback_handler(t_zc *, t_zht, void *);
void		remote_stdin_handler(t_zc *, const char *, void *);
void		remote_cmd_welcome_handler(t_zc *, void *);
void		remote_rmt_pubkey_handler(t_zc *, const char *, void *);

#endif /* !REMOTE_H_*/
