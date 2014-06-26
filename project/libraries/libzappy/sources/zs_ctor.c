/*
** zs_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 09:25:07 2014 raphael defreitas
** Last update Thu Jun 26 13:03:35 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

static int	init_socket(t_socket *sock, int port)
{
  if (socket_bind(sock, INADDR_ANY, port) == RET_FAILURE ||
      socket_listen(sock, ZS_QUEUE_LEN) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

static void	default_values(t_zs *this)
{
  this->socket = NULL;
  this->clients = NULL;
  this->hooks = NULL;
  FD_ZERO(&this->rfds);
  FD_ZERO(&this->wfds);
  zs_disable_timeout(this);
}

int		zs_ctor(t_zs *this, int port)
{
  if (this == NULL)
    return (RET_FAILURE);
  default_values(this);
  if ((this->socket = socket_new()) == NULL ||
      socket_ctor(this->socket, AF_INET, SOCK_STREAM, 0) == RET_FAILURE ||
      (this->clients = list_new(&zc_delete)) == NULL)
    return (RET_FAILURE);
  if (init_socket(this->socket, port) == RET_FAILURE)
    return (RET_FAILURE);
  if ((this->hooks = calloc(ZHT_MAX, sizeof(t_zh))) == NULL)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
