/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Thu Jun 26 14:42:15 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

static void	zs_treat_new_client(t_zs *this)
{
  t_zc		*zc;

  if (FD_ISSET(socket_fd(this->socket), &this->rfds))
    {
      if ((zc = zc_new()) == NULL ||
	  (zc->socket = socket_accept(this->socket)) == NULL ||
	  list_enqueue(this->clients, zc) == RET_FAILURE)
	{
	  zc_delete(zc);
	  zs_handle_errno(this);
	  return ;
	}
      zs_handle_client_connected(this, zc);
    }
}

static void	zs_treat_wfds(t_zs *this)
{

}

static void	zs_treat_rfds(t_zs *this)
{

}

void		zs_treat_fds(t_zs *this)
{
  zs_treat_new_client(this);
  zs_treat_wfds(this);
  zs_treat_rfds(this);
}
