/*
** zs_send_rmt_teams.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/commands
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon Jul  7 10:16:06 2014 raphael defreitas
** Last update Thu Jul 10 01:11:03 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<string.h>

#include	"list.h"
#include	"zappy.h"
#include	"_zappy.h"

static char	*build_response(const t_list *teams)
{
  t_iterator	it;
  char		*res;
  char		*team;

  if ((res = strdup("teams ")) == NULL)
    return (NULL);
  iterator_ctor(&it, (t_list *)teams, IT_DATA);
  while ((team = iterator_current(&it)))
    {
      iterator_next(&it);
      if ((res = realloc(res, strlen(res) + strlen(team) + 5)) == NULL)
	return (NULL);
      strcat(res, "[");
      strcat(res, team);
      strcat(res, "] ");
    }
  iterator_dtor(&it);
  return (res);
}

void		zs_send_rmt_teams(t_zs *this, t_zc *zc, const t_list *teams)
{
  char		*buf;
  char		*tmp;

  if (this == NULL)
    return ;
  if (zc->key_encrypt == NULL ||
      (buf = build_response(teams)) == NULL ||
      zt_rmt_encrypt(zc->key_encrypt, buf, &tmp) == RET_FAILURE ||
      tmp == NULL)
    {
      zs_handle_errno(this, "encryption failed");
      return ;
    }
  zs_send(this, zc, "RMT CMD ");
  zs_send(this, zc, tmp);
  zs_send(this, zc, "\n");
  free(buf);
  free(tmp);
}
