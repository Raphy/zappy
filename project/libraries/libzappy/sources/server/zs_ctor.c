/*
** zs_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 09:25:07 2014 raphael defreitas
** Last update Sat Jul 12 22:58:20 2014 raphael defreitas
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
  this->max_fd = 0;
  this->uid = 1;
  zs_disable_timeout(this);
  this->has_to_stop = false;
  this->cmd_fptrs = NULL;
  this->pubkey = NULL;
  this->key_encrypt = NULL;
  this->key_decrypt = NULL;
  this->high_load_limit = 30;
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
      zs_ctor_cmd_fptrs(this) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
