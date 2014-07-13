/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Sat Jul 12 20:42:05 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zs_treat_client_connection(t_zs *this)
{
  t_zc		*zc;

  if ((zc = zc_new()) == NULL ||
      (zc->socket = socket_accept(this->socket)) == NULL ||
      list_enqueue(this->clients, zc) == RET_FAILURE)
	{
	  zc_delete(zc);
	  zs_handle_errno(this, "client connection failed");
	  return ;
	}
  zc->uid = this->uid;
  this->uid++;
  if (zc->socket->fd > this->max_fd)
    this->max_fd = zc->socket->fd;
  zs_handle_client_connected(this, zc);
}
