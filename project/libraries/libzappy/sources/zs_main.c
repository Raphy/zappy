/*
** zs_main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 09:46:52 2014 raphael defreitas
** Last update Thu May 15 11:21:53 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

static void	set_fds(t_zs *this)
{
  t_iterator	it;
  t_zc		*client;

  FD_ZERO(&this->rfds);
  FD_ZERO(&this->wfds);
  FD_SET(socket_fd(this->socket), &this->rfds);
  iterator_ctor(&it, &this->clients, IT_DATA);
  while ((client = iterator_current(&it)))
    {
      iterator_next(&it);
      FD_SET(socket_fd(client->socket), &this->rfds);
    }
}

static int	server_select(t_zs *this)
{
  t_timeval	to;

  set_fds(this);
  to = this->timeout;
  printf("[WAITING] Timeout: %lds %ldµs - Clients: %ld\n",
	 to.tv_sec, to.tv_usec, list_length(&this->clients));
  if (to.tv_sec == 0 && to.tv_usec == 0)
    return (select(FD_SETSIZE, &this->rfds, &this->wfds, NULL, NULL));
  return (select(FD_SETSIZE, &this->rfds, &this->wfds, NULL, &to));
}

void		zs_main(t_zs *this)
{
  int		s_ret;

  while (42)
    {
      s_ret = server_select(this);
      if (s_ret == RET_ERROR)
	{
	  if (errno != EINTR)
	    exit(fprintf(stderr, "[FATAL ERROR]: %s\n", strerror(errno)));
	  else
	    fprintf(stderr, "[ERROR] %s\n", strerror(errno));
	}
      if (s_ret == 0)
	zs_handle_timeout(this);
      zs_treat_new_client(this);
      /*zs_treat_clients(this);*/
    }
}
