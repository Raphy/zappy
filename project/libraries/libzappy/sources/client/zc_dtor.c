/*
** zc_dtor.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:50:11 2014 raphael defreitas
** Last update Tue Jul  1 04:42:57 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

void		zc_dtor(t_zc *this)
{
  if (this == NULL)
    return ;
  socket_delete(this->socket);
  free(this->hooks);
  list_delete(this->pckts_rcvd);
  list_delete(this->pckts_to_snd);
  list_delete(this->cmd_fptrs);
  list_delete(this->commands);
  list_delete(this->stdin);
  zt_rsa_delete(this->pubkey);
}
