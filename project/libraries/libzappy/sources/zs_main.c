/*
** zs_main.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 13:33:49 2014 raphael defreitas
** Last update Fri Jun 27 14:01:15 2014 raphael defreitas
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

static void	print_pckts(t_zs *this)
{
  t_iterator	it;
  t_iterator	it2;
  t_zc		*zc;
  char		*data;

  printf("##### DUMP ######\n");
  iterator_ctor(&it, this->clients, IT_DATA);
  while ((zc = iterator_current(&it)))
    {
      iterator_next(&it);
      printf("Client #%d\n", zc->socket->fd);
      iterator_ctor(&it2, zc->pckts_rcvd, IT_DATA);
      while ((data = iterator_current(&it2)))
	{
	  iterator_next(&it2);
	  printf("\t%s\n", data);
	}
      iterator_dtor(&it2);
    }
  iterator_dtor(&it);
  printf("#################\n");
}

void		zs_main(t_zs *this)
{
  int		select_ret;
  
  if (this == NULL)
    return ;
  while (!this->has_to_stop)
    {
      print_pckts(this);
      select_ret = zs_select(this);
      if (select_ret == RET_ERROR)
	{
	  zs_handle_errno(this);
	  continue ;
	}
      else if (select_ret == 0)
	zs_handle_timeout(this);
      zs_treat_fds(this);
    }
}
