/*
** zs_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 09:25:07 2014 raphael defreitas
** Last update Sun Jun 29 06:09:04 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

static int	init_socket(t_socket *sock, int port)
{
  if (socket_bind(sock, INADDR_ANY, port) == RET_FAILURE ||
      socket_listen(sock, 4242) == RET_FAILURE)
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
  this->has_to_stop = false;
  this->cmd_fptrs = NULL;
}

static int	init_cmd_fptrs(t_list *cmd_fptrs)
{
  if (list_enqueue(cmd_fptrs, (void *)&zs_cmd_team_name) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

int		zs_ctor(t_zs *this, int port, t_list *team_names)
{
  if (this == NULL)
    return (RET_FAILURE);
  this->team_names = team_names;
  default_values(this);
  if ((this->socket = socket_new()) == NULL ||
      socket_ctor(this->socket, AF_INET, SOCK_STREAM, 0) == RET_FAILURE ||
      (this->clients = list_new(&zc_delete)) == NULL ||
      init_socket(this->socket, port) == RET_FAILURE ||
      (this->hooks = calloc(ZHT_MAX, sizeof(t_zh))) == NULL ||
      (this->cmd_fptrs = list_new(NULL)) == NULL ||
      init_cmd_fptrs(this->cmd_fptrs) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
