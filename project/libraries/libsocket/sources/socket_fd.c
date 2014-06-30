/*
** socket_fd.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Apr 18 20:06:05 2014 raphael defreitas
** Last update Mon Jun 30 14:26:27 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"socket.h"

int		socket_fd(t_socket *this)
{
  if (this == NULL)
    return (RET_ERROR);
  return (this->fd);
}
