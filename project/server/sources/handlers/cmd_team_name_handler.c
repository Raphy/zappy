/*
** cmd_team_name_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Thu Jul 10 01:12:36 2014 damien sauvalle
*/

#include	<stdio.h>

#include	"zappy.h"

void		cmd_team_name_handler(__attribute__((unused))t_zs *zs,
				      t_zc *zc,
				      const char *team_name,
				      __attribute__((unused))void *data)
{
  printf("TEAM NAME HANDLER\n");
  if (zc_get_type(zc) != ZCT_UNKNOWN)
    {
      zc_disconnect(zc);
      return ;
    }
  printf("[%d] is player. Team: %s\n", zc->socket->fd, team_name);
  zc_set_type(zc, ZCT_PLAYER);
}
