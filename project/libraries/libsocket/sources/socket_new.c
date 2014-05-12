/*
** socket_new.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Apr 15 00:01:30 2014 raphael defreitas
** Last update Tue Apr 15 00:02:42 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"socket.h"

t_socket	*socket_new(void)
{
  t_socket	*this;

  this = calloc(1, sizeof(t_socket));
  return (this);
}
