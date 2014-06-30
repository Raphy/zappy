/*
** socket_connect.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:48:48 2014 raphael defreitas
** Last update Mon Jun 30 14:26:54 2014 raphael defreitas
*/

#include	<arpa/inet.h>
#include	<netinet/in.h>
#include	<sys/socket.h>

#include	"socket.h"

int		socket_connect(t_socket *this, in_addr_t address, int port)
{
  if (this == NULL)
    return (RET_FAILURE);
  this->addr.sin_family = this->domain;
  this->addr.sin_addr.s_addr = address;
  this->addr.sin_port = htons(port);
  if (connect(this->fd, (struct sockaddr *)&this->addr, this->addr_len) == -1)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
