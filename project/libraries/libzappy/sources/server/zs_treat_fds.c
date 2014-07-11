/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Sat Jul 12 00:57:15 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<errno.h>
#include	<stdlib.h>
#include	<string.h>
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
	  zs_handle_errno(this, "client connection failed");
	  return ;
	}
      zc->uid = this->uid;
      this->uid++;
      if (zc->socket->fd > this->max_fd)
	this->max_fd = zc->socket->fd;
      zs_handle_client_connected(this, zc);
    }
}

static void	treat_read_zc(t_zs *this, t_zc *zc)
{
  char		buf[SOCK_BUF_LEN + 1];
  int		rlen;

  if (zc->has_to_disconnect || zc->has_to_stop)
    return ;
  rlen = socket_read(zc->socket, buf, SOCK_BUF_LEN);
  if (rlen == RET_ERROR && errno != ECONNRESET)
    zs_handle_errno(this, "socket read failed");
  else if (rlen == RET_ERROR)
    zc_disconnect(zc);
  else if (rlen > 0)
    {
      buf[rlen] = 0;
      if (strcmp(buf, "stop\n") == 0)
	zs_stop(this);
      else if (zt_append_buffer(zc->pckts_rcvd, buf) == RET_FAILURE)
	zs_handle_errno(this, "network received data storage failed");
    }
}

static void	treat_write_zc(t_zs *this, t_zc *zc)
{
  int		wlen;
  char		*data;

  if (zc->has_to_disconnect || zc->has_to_stop)
    return ;
  if (list_length(zc->pckts_to_snd) == 0)
    return ;
  data = NULL;
  if ((data = list_pop(zc->pckts_to_snd)) == NULL)
    return ;
  wlen = socket_write(zc->socket, data, strlen(data));
  free(data);
  if (wlen == RET_ERROR && errno != 0 && errno != ECONNRESET)
    zs_handle_errno(this, "socket write failed");
  else if (wlen == RET_ERROR)
    zc_disconnect(zc);
}

void	zs_treat_fds(t_zs *this)
{
  t_iterator	it;
  t_zc		*zc;

  treat_client_connection(this);
  iterator_ctor(&it, this->clients, IT_DATA);
  while ((zc = iterator_current(&it)))
    {
      iterator_next(&it);
      if (FD_ISSET(socket_fd(zc->socket), &this->rfds))
	treat_read_zc(this, zc);
      if (FD_ISSET(socket_fd(zc->socket), &this->wfds))
	treat_write_zc(this, zc);
      zs_treat_zc(this, zc);
    }
  iterator_dtor(&it);
}
