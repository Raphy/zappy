/*
** zc_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 02:17:37 2014 raphael defreitas
** Last update Sat Jul 12 23:13:12 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<errno.h>
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/select.h>
#include	<unistd.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

static void	treat_read(t_zc *this)
{
  char		buf[SOCK_BUF_LEN + 1];
  int		rlen;

  rlen = socket_read(this->socket, buf, SOCK_BUF_LEN);
  printf("[libzappy] read from server - read return:%d\n", rlen);
  if (rlen == RET_ERROR)
    this->has_to_stop = true;
  else if (rlen > 0)
    {
      buf[rlen] = 0;
      printf("\t[%s]\n", buf);
      if (zt_append_buffer(this->pckts_rcvd, buf) == RET_FAILURE)
	zc_handle_errno(this, "network received data storage failed");
    }
}

static void	treat_write(t_zc *this)
{
  int		wlen;
  char		*data;

  if (list_length(this->pckts_to_snd) == 0)
    return ;
  if ((data = list_pop(this->pckts_to_snd)) == NULL)
    return ;
  wlen = socket_write(this->socket, data, strlen(data));
  printf("[libzappy] write to server - write return:%d\n", wlen);
  free(data);
  if (wlen == RET_ERROR)
    zc_handle_errno(this, "socket write failed");
  else
    printf("\t[%s]\n", data);
}

static void	treat_stdin(t_zc *this)
{
  char		buf[SOCK_BUF_LEN + 1];
  int		rlen;

  rlen = read(0, buf, SOCK_BUF_LEN);
  if (rlen == RET_ERROR)
    zc_handle_errno(this, "stdin read failed");
  else if (rlen > 0)
    {
      buf[rlen] = 0;
      if (zt_append_buffer(this->stdin, buf) == RET_FAILURE)
	zc_handle_errno(this, "stdin data storage failed");
    }
}

void		zc_treat_fds(t_zc *this)
{
  if (FD_ISSET(0, &this->rfds))
    treat_stdin(this);
  if (FD_ISSET(socket_fd(this->socket), &this->rfds))
    treat_read(this);
  if (FD_ISSET(socket_fd(this->socket), &this->wfds))
    treat_write(this);
  zc_treat(this);
}
