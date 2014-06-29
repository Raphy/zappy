/*
** remote.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Sun Jun 29 18:38:50 2014 raphael defreitas
** Last update Sun Jun 29 19:00:29 2014 raphael defreitas
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

#endif /* !REMOTE_H_*/
