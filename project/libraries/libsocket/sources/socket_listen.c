/*
** socket_listen.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:57:53 2014 raphael defreitas
** Last update Mon Jun 30 14:26:10 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<sys/socket.h>

#include	"socket.h"

int		socket_listen(t_socket *this, int queue_size)
{
  if (this == NULL)
    return (RET_FAILURE);
  if (listen(this->fd, queue_size) == -1)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
