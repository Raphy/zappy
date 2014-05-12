/*
** socket_write.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Apr 15 20:36:57 2014 raphael defreitas
** Last update Tue Apr 15 20:50:42 2014 raphael defreitas
*/

#include	<unistd.h>

#include	"socket.h"

int		socket_write(t_socket *this, const void *buf, size_t len)
{
  int		ret;

  if ((ret = write(this->fd, buf, len)) == RET_ERROR)
    return (RET_ERROR);
  return (ret);
}
