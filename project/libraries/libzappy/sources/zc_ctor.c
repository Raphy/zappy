/*
** zc_ctor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 16:30:07 2014 raphael defreitas
** Last update Thu May 15 10:52:59 2014 raphael defreitas
*/

#include	"zappy.h"

/*static int	init_socket(t_socket *sock, const char *host, int p)
{
  t_hostent	*hi;

  if (socket_ctor(sock, AF_INET, SOCK_STREAM, 0) == RET_FAILURE ||
      (hi = gethostbyname(host)) == NULL ||
      socket_connect(sock, *(in_addr_t *)hi->h_addr_list[0], p) == RET_FAILURE)
    return (RET_FAILURE);
  return (RET_SUCCESS);
  }*/

int		zc_ctor(t_zc *this)
{
  return (RET_SUCCESS);
}
