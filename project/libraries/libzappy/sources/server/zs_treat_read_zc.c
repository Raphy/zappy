/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Sat Jul 12 23:04:12 2014 raphael defreitas
*/

#include	<errno.h>

#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

void		zs_treat_read_zc(t_zs *this, t_zc *zc)
{
  char		buf[SOCK_BUF_LEN + 1];
  int		rlen;

  if (zc->has_to_disconnect || zc->has_to_stop)
    return ;
  rlen = socket_read(zc->socket, buf, SOCK_BUF_LEN);
  printf("[libzappy] read from %d - read return:%d\n", zc->socket->fd, rlen);
  if (rlen == RET_ERROR && errno != 0 && errno != ECONNRESET)
    zs_handle_errno(this, "socket read failed");
  else if (rlen == RET_ERROR)
    zc_disconnect(zc);
  else if (rlen > 0)
    {
      buf[rlen] = 0;
      printf("\t[%s]\n", buf);
      if (zt_append_buffer(zc->pckts_rcvd, buf) == RET_FAILURE)
	zs_handle_errno(this, "network received data storage failed");
    }
}
