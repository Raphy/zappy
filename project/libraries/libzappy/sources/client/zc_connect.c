/*
** zc_connect.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 13:13:58 2014 raphael defreitas
** Last update Mon Jun 30 17:35:18 2014 raphael defreitas
*/

#include	<netdb.h>
#include	<stdlib.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static int	init_cmd_fptrs(t_list *cmd_fptrs)
{
  if (list_enqueue(cmd_fptrs, (void *)&zc_cmd_welcome) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}

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
  if ((this->cmd_fptrs = list_new(NULL)) == NULL ||
      init_cmd_fptrs(this->cmd_fptrs) == RET_FAILURE ||
      (this->stdin = list_new(&free)) == NULL)
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
