/*
** zs_dtor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:24:20 2014 raphael defreitas
** Last update Thu Jun 26 11:25:31 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

void		zs_dtor(t_zs *this)
{
  if (this == NULL)
    return ;
  socket_dtor(&this->socket);
  list_dtor(&this->clients);
}
