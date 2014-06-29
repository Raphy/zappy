/*
** zc_main.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 01:04:22 2014 raphael defreitas
** Last update Sun Jun 29 03:55:50 2014 raphael defreitas
*/

#include	<stdlib.h>
#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

static void	set_fds(t_zc *this)
{
  FD_ZERO(&this->rfds);
  FD_ZERO(&this->wfds);
  FD_SET(socket_fd(this->socket), &this->rfds);
  FD_SET(0, &this->rfds); /* To Remove */
  if (list_length(this->pckts_to_snd) > 0)
    FD_SET(socket_fd(this->socket), &this->wfds);
}

static int	zc_select(t_zc *this)
{
  t_timeval	to;

  set_fds(this);
  to = this->timeout;
  if (to.tv_sec == 0 && to.tv_usec == 0)
    return (select(FD_SETSIZE, &this->rfds, &this->wfds, NULL, NULL));
  return (select(FD_SETSIZE, &this->rfds, &this->wfds, NULL, &to));
}

void		zc_main(t_zc *this)
{
  int		select_ret;

  if (this == NULL)
    return ;
  zc_handle_connected(this);
  while (!this->has_to_stop)
    {
      select_ret = zc_select(this);
      if (select_ret == RET_ERROR)
	{
	  zc_handle_errno(this, "select failed");
	  continue ;
	}
      else if (select_ret == 0)
	zc_handle_timeout(this);
      zc_treat_fds(this);
    }
  zc_handle_disconnected(this);
}
