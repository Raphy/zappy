/*
** zc_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 02:17:37 2014 raphael defreitas
** Last update Sun Jun 29 06:46:28 2014 raphael defreitas
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
  if (rlen == RET_ERROR/* && errno != 0 && errno != ECONNRESET*/)
    this->has_to_stop = true;
  else if (rlen > 0)
    {
      buf[rlen] = 0;
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
  if (wlen == RET_ERROR)
    zc_handle_errno(this, "socket write failed");
}

/* To Remove Later */
static void	treat_stdin(t_zc *this)
{
  char		buf[SOCK_BUF_LEN + 1];
  int		rlen;

  rlen = read(0, buf, SOCK_BUF_LEN);
  if (rlen == RET_ERROR/* && errno != 0 && errno != ECONNRESET*/)
    zc_handle_errno(this, "stdin read failed");
  else if (rlen > 0)
    {
      buf[rlen] = 0;
      if (strcmp(buf, "exit\n") == 0)
	this->has_to_stop = true;
      else if (list_enqueue(this->pckts_to_snd, strdup(buf)) == RET_FAILURE)
	zc_handle_errno(this, "stdin command storage failed");
    }
}

static void	treat_command(t_zc *this)
{
  char		*command;
  int		ret;

  if (list_length(this->pckts_rcvd) == 0)
    return ;
  command = NULL;
  while ((ret = zt_build_command(this->pckts_rcvd, &command)) == RET_SUCCESS &&
	 command != NULL)
    {
      zc_dispatch_command(this, command);
      free(command);
      command = NULL;
    }
  if (ret == RET_FAILURE)
    zc_handle_errno(this, "command parsing failed");
}

void		zc_treat_fds(t_zc *this)
{
  if (FD_ISSET(0, &this->rfds))
    treat_stdin(this); /* To Remove Later */
  if (FD_ISSET(socket_fd(this->socket), &this->rfds))
    treat_read(this);
  if (FD_ISSET(socket_fd(this->socket), &this->wfds))
    treat_write(this);
  treat_command(this);
}
