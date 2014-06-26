/*
** zs_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 09:25:07 2014 raphael defreitas
** Last update Thu Jun 26 11:24:37 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

static int	init_socket(t_socket *sock, int port)
{
  if (socket_bind(sock, INADDR_ANY, port) == RET_FAILURE)
    {
      perror("error: socket bind");
      return (RET_FAILURE);
    }
  if (socket_listen(sock, ZS_QUEUE_LEN) == RET_FAILURE)
    {
      perror("error: socket listen");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

int		zs_ctor(t_zs *this, int port)
{
  if (this == NULL)
    return (RET_FAILURE);
  bzero(&this->hooks, sizeof(this->hooks));
  FD_ZERO(&this->rfds);
  FD_ZERO(&this->wfds);
  zs_disable_timeout(this);
  if (socket_ctor(&this->socket, AF_INET, SOCK_STREAM, 0) == RET_FAILURE ||
      list_ctor(&this->clients, &zc_delete) == RET_FAILURE)
    return (RET_FAILURE);
  if (init_socket(&this->socket, port))
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
