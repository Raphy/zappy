/*
** socket_dtor.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Apr 14 23:46:21 2014 raphael defreitas
** Last update Mon Jun 30 14:23:32 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"socket.h"

void		socket_dtor(t_socket *this)
{
  if (this == NULL)
    return ;
  if (this->fd > 0)
    close(this->fd);
}
