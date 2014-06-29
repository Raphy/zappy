/*
** zs_main.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 13:33:49 2014 raphael defreitas
** Last update Sun Jun 29 01:13:15 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

static void	set_fds(t_zs *this)
{
  t_iterator	it;
  t_item	*item;
  t_zc		*zc;

  FD_ZERO(&this->rfds);
  FD_ZERO(&this->wfds);
  FD_SET(socket_fd(this->socket), &this->rfds);
  iterator_ctor(&it, this->clients, IT_ITEM);
  while ((item = iterator_current(&it)))
    {
      iterator_next(&it);
      zc = item_data(item);
      if (zc->has_to_disconnect)
	{
	  zs_handle_client_disconnected(this, zc);
	  zc_delete(zc);
	  list_unlink(this->clients, item);
	}
      else
	{
	  FD_SET(socket_fd(zc->socket), &this->rfds);
	  if (list_length(zc->pckts_to_snd) > 0)
	    FD_SET(socket_fd(zc->socket), &this->wfds);
	}
    }
}

static int	zs_select(t_zs *this)
{
  t_timeval	to;

  set_fds(this);
  to = this->timeout;
  if (to.tv_sec == 0 && to.tv_usec == 0)
    return (select(FD_SETSIZE, &this->rfds, &this->wfds, NULL, NULL));
  return (select(FD_SETSIZE, &this->rfds, &this->wfds, NULL, &to));
}

void		zs_main(t_zs *this)
{
  int		select_ret;

  if (this == NULL)
    return ;
  while (!this->has_to_stop)
    {
      select_ret = zs_select(this);
      if (select_ret == RET_ERROR)
	{
	  zs_handle_errno(this, "select failed");
	  continue ;
	}
      else if (select_ret == 0)
	zs_handle_timeout(this);
      zs_treat_fds(this);
    }
}
