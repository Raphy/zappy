/*
** socket_ctor.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:38:58 2014 raphael defreitas
** Last update Mon Jun 30 14:25:14 2014 raphael defreitas
*/

#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<stdlib.h>
#include	<strings.h>

#include	"socket.h"

int		socket_ctor(t_socket *this, int domain, int type, int protocol)
{
  if (this == NULL)
    return (RET_FAILURE);
  this->addr_len = sizeof(t_sockaddr_in);
  bzero(&this->addr, sizeof(t_sockaddr_in));
  this->domain = domain;
  if ((this->fd = socket(domain, type, protocol)) == -1)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
