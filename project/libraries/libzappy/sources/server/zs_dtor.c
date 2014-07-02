/*
** zs_dtor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:24:20 2014 raphael defreitas
** Last update Wed Jul  2 02:13:18 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zs_dtor(t_zs *this)
{
  if (this == NULL)
    return ;
  socket_delete(this->socket);
  list_delete(this->clients);
  list_delete(this->cmd_fptrs);
  free(this->hooks);
  free(this->pubkey);
}
