/*
** zc_dtor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:50:11 2014 raphael defreitas
** Last update Thu Jun 26 12:58:34 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"socket.h"
#include	"zappy.h"

void		zc_dtor(t_zc *this)
{
  if (this == NULL)
    return ;
  socket_delete(this->socket);
  free(this->hooks);
}
