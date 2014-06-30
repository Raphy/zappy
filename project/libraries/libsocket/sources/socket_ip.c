/*
** socket_ip.c for libsocket in /home/raphy/Epitech/Tech_2/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Apr 19 03:02:01 2014 raphael defreitas
** Last update Mon Jun 30 14:31:19 2014 raphael defreitas
*/

#include	<arpa/inet.h>
#include	<stdlib.h>

#include	"socket.h"

const char	*socket_ip(t_socket *this)
{
  if (this == NULL)
    return (NULL);
  return (inet_ntoa(this->addr.sin_addr));
}
