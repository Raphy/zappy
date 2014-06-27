/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Fri Jun 27 14:02:14 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<errno.h>
#include	<stdio.h>
#include	<string.h>

#include	<stdlib.h>
#include	<sys/select.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

static void	treat_client_connection(t_zs *this)
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

static void	treat_read_zc(t_zs *this, t_zc *zc)
{
  char		buf[SOCK_BUF_LEN + 1];
  int		rlen;
  char		*tmp;

  rlen = socket_read(zc->socket, buf, SOCK_BUF_LEN);
  if (rlen == RET_ERROR && errno != 0)
    zs_handle_errno(this);
  else if (rlen == RET_ERROR)
    zc->has_to_disconnect = true;
  else if (rlen > 0)
    {
      buf[rlen - 1] = 0;
      if ((tmp = strdup(buf)) == NULL ||
	  list_enqueue(zc->pckts_rcvd, tmp) == RET_FAILURE)
	{
	  free(tmp);
	  zs_handle_errno(this);
	  return ;
	}
      if (strcmp(tmp, "stop") == 0)
	this->has_to_stop = true;
    }
}

static void	treat_write_zc(t_zs *this, t_zc *zc)
{
  //char		buf[SOCK_BUF_LEN + 1];
  int		wlen;
  char		*data;

  if (list_length(zc->pckts_to_snd) == 0)
    return ;
  data = list_front(zc->pckts_to_snd);
  wlen = socket_write(zc->socket, data, strlen(data));
  if (wlen == RET_ERROR && errno != 0)
    zs_handle_errno(this);
}

static void	treat_rwfds(t_zs *this)
{
  t_iterator	it;
  t_zc		*zc;

  iterator_ctor(&it, this->clients, IT_DATA);
  while ((zc = iterator_current(&it)))
    {
      iterator_next(&it);
      if (FD_ISSET(socket_fd(zc->socket), &this->rfds))
	treat_read_zc(this, zc);
      if (FD_ISSET(socket_fd(zc->socket), &this->wfds))
	treat_write_zc(this, zc);
    }
  iterator_dtor(&it);
}

void		zs_treat_fds(t_zs *this)
{
  treat_client_connection(this);
  treat_rwfds(this);
}
