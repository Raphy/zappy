/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Thu Jun 26 15:54:50 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>

#include	<stdlib.h>
#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"

static void	zs_treat_wfds(t_zs *this)
{

}

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

static void	zs_treat_rfds(t_zs *this)
{
  t_iterator	it;
  t_zc		*zc;
  int	rlen;
  char		buf[SOCK_BUF_LEN + 1];

  zs_treat_new_client(this);
  iterator_ctor(&it, this->clients, IT_DATA);
  while ((zc = iterator_current(&it)))
    {
      iterator_next(&it);
      if (FD_ISSET(socket_fd(zc->socket), &this->rfds))
	{
	  buf[0] = 0;
	  rlen = socket_read(zc->socket, buf, SOCK_BUF_LEN);
	  if (rlen >= 2)
	    buf[rlen - 1] = 0;
	  printf("rlen: %d [%s] [%d]\n", rlen, buf, errno);
	  if (rlen <= 0 && errno != 0)
	    {
	      perror("sread");
	    }
	}
    }
}

void		zs_treat_fds(t_zs *this)
{
  zs_treat_wfds(this);
  zs_treat_rfds(this);
}
