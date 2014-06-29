/*
** zc_connect.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 13:13:58 2014 raphael defreitas
** Last update Sun Jun 29 01:56:48 2014 raphael defreitas
*/

#include	<netdb.h>
#include	<stdlib.h>

#include	"zappy.h"

int		zc_connect(t_zc *this, const char *host, int port)
{
  t_hostent	*hi;
  in_addr_t	address;

  if (this == NULL)
    return (RET_FAILURE);
  if ((this->socket = socket_new()) == NULL ||
      socket_ctor(this->socket, AF_INET, SOCK_STREAM, 0) == RET_FAILURE)
    return (RET_FAILURE);
  if ((hi = gethostbyname(host)) == NULL)
    return (RET_FAILURE);
  address = *(in_addr_t *)hi->h_addr_list[0];
  if (socket_connect(this->socket, address, port) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
