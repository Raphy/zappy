/*
** socket_delete.c for libsocjet in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Apr 15 00:00:49 2014 raphael defreitas
** Last update Mon Jun 30 14:27:29 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"socket.h"

void		socket_delete(t_socket *this)
{
  socket_dtor(this);
  free(this);
}
