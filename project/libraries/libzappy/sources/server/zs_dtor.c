/*
** zs_dtor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:24:20 2014 raphael defreitas
** Last update Tue Jul  1 17:50:00 2014 raphael defreitas
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
  zt_rsa_delete(this->public_key);
  zt_rsa_delete(this->public_key);
  free(this->public_key_str);
}
