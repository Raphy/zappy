/*
** socket_connect.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:48:48 2014 raphael defreitas
** Last update Tue Apr 15 18:59:09 2014 raphael defreitas
*/

#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>

#include	"socket.h"

int		socket_connect(t_socket *this, in_addr_t address, int port)
{
  this->addr.sin_family = this->domain;
  this->addr.sin_addr.s_addr = address;
  this->addr.sin_port = htons(port);
  if (connect(this->fd, (struct sockaddr *)&this->addr, this->addr_len) == -1)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
