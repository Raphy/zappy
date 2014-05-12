/*
** socket_ip.c for libsocket in /home/raphy/Epitech/Tech_2/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Apr 19 03:02:01 2014 raphael defreitas
** Last update Sat Apr 19 03:03:03 2014 raphael defreitas
*/

#include	<arpa/inet.h>

#include	"socket.h"

const char	*socket_ip(t_socket *this)
{
  return (inet_ntoa(this->addr.sin_addr));
}
