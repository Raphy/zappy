/*
** zc_ctor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:49:43 2014 raphael defreitas
** Last update Thu Jun 26 13:14:36 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"socket.h"
#include	"zappy.h"

/*static int	init_socket(t_socket *sock, const char *host, int p)
{
  t_hostent	*hi;

  if ((hi = gethostbyname(host)) == NULL ||
      socket_connect(sock, *(in_addr_t *)hi->h_addr_list[0], p) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
  }*/

static void	default_values(t_zc *this)
{
  this->socket = NULL;
  this->hooks = NULL;
  this->is_graphic = -1;
  zc_disable_timeout(this);
}

int		zc_ctor(t_zc *this)
{
  if (this == NULL)
    return (RET_FAILURE);
  default_values(this);
  if ((this->hooks = calloc(ZHT_MAX, sizeof(t_zh))) == NULL)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
