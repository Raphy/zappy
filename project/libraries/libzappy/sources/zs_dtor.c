/*
** zs_dtor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 15:48:31 2014 raphael defreitas
** Last update Thu May 15 10:59:53 2014 raphael defreitas
*/

#include	"socket.h"
#include	"zappy.h"

void		zs_dtor(t_zs *this)
{
  if (this->socket)
    socket_delete(this->socket);
}
