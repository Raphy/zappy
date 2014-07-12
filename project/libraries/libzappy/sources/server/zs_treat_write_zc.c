/*
** zs_treat_fds.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 14:29:15 2014 raphael defreitas
** Last update Sat Jul 12 21:47:49 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"list.h"
#include	"socket.h"
#include	"zappy.h"
#include	"_zappy.h"

static void	write_to_zc(t_zs *this, t_zc *zc,
			    const char *data, size_t data_len)
{
  int		wlen;

  printf("[libzappy] write [%lu][%s]\n", data_len, data);
  wlen = socket_write(zc->socket, data, data_len);
  if (wlen == RET_ERROR && errno != 0 && errno != ECONNRESET)
	zs_handle_errno(this, "socket write failed");
  else if (wlen == RET_ERROR)
    zc_disconnect(zc);
}

static void	low_load(t_zs *this, t_zc *zc)
{
  int		i;
  char		*data;

  if (zc->has_to_disconnect || zc->has_to_stop)
    return ;
  i = 0;
  while ((data = list_pop(zc->pckts_to_snd)) && i < 20)
    {
      write_to_zc(this, zc, data, strlen(data));
      free(data);
      i++;
    }
}

static bool	can_use_high_load(char **buf, size_t *buf_len)
{
  if (*buf == NULL)
    *buf = calloc(SOCK_BUF_LEN + 1, sizeof(char));
  if (*buf == NULL)
    return (false);
  (*buf)[0] = 0;
  *buf_len = 0;
  return (true);
}

static void	high_load(t_zs *this, t_zc *zc)
{
  static char	*buf = NULL;
  char		*data;
  size_t	buflen;
  size_t	data_len;

  if (!can_use_high_load(&buf, &buflen))
    {
      low_load(this, zc);
      return ;
    }
  while ((data = list_pop(zc->pckts_to_snd)))
    {
      if ((data_len = strlen(data)) + buflen < SOCK_BUF_LEN && strcat(buf, data))
	{
	  free(data);
	  buflen += data_len;
	  continue ;
	}
      list_push(zc->pckts_to_snd, data);
      break ;
    }
  if (buf[0] && buflen > 0)
    write_to_zc(this, zc, buf, buflen);
  else
    low_load(this, zc);
}

void		zs_treat_write_zc(t_zs *this, t_zc *zc)
{
  if (list_length(this->clients) >= this->high_load_limit)
    high_load(this, zc);
  else
    low_load(this, zc);
}
