/*
** socket_read.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Apr 15 20:39:42 2014 raphael defreitas
** Last update Mon Jun 30 14:24:19 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"socket.h"

int		socket_read(t_socket *this, void *buf, size_t len)
{
  int		ret;

  if (this == NULL)
    return (RET_ERROR);
  if ((ret = read(this->fd, buf, len)) == RET_ERROR || ret == 0)
    return (RET_ERROR);
  return (ret);
}
