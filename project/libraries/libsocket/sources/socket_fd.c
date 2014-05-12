/*
** socket_fd.c for libsocket in /home/raphy/Epitech/Libraries/libsocket/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Apr 18 20:06:05 2014 raphael defreitas
** Last update Fri Apr 18 20:06:37 2014 raphael defreitas
*/

#include	"socket.h"

int		socket_fd(t_socket *this)
{
  return (this->fd);
}
