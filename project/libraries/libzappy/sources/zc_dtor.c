/*
** zc_dtor.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 16:40:45 2014 raphael defreitas
** Last update Mon May 12 16:41:15 2014 raphael defreitas
*/

#include	"socket.h"
#include	"zappy.h"

void		zc_dtor(t_zc *this)
{
  socket_dtor(&this->socket);
}
