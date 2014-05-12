/*
** socket_listen.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:57:53 2014 raphael defreitas
** Last update Mon Apr 14 23:58:36 2014 raphael defreitas
*/

#include	<sys/socket.h>

#include	"socket.h"

int		socket_listen(t_socket *this, int queue_size)
{
  if (listen(this->fd, queue_size) == -1)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
