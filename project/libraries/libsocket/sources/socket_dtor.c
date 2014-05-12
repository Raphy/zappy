/*
** socket_dtor.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:46:21 2014 raphael defreitas
** Last update Mon Apr 14 23:46:53 2014 raphael defreitas
*/

#include	<unistd.h>

#include	"socket.h"

void		socket_dtor(t_socket *this)
{
  if (this->fd > 0)
    close(this->fd);
}
