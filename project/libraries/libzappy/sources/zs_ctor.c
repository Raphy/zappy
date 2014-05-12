/*
** zs_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 15:33:31 2014 raphael defreitas
** Last update Mon May 12 17:55:25 2014 raphael defreitas
*/

#include	"socket.h"
#include	"zappy.h"

static int	init_socket(t_socket *sock, int port)
{
  if (socket_ctor(sock, AF_INET, SOCK_STREAM, 0) == RET_FAILURE ||
      socket_bind(sock, INADDR_ANY, port) ||
      socket_listen(sock, 42) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		zs_ctor(t_zs *this, int port)
{
  if (init_socket(&this->socket, port) == RET_FAILURE ||
      list_ctor(&this->clients, &zc_delete) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
