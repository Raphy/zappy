/*
** server_pnw.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 01:55:54 2014 damien sauvalle
** Last update Sat Jul 12 12:56:54 2014 damien sauvalle
*/

#include	<stdio.h>

#include	"server.h"
#include	"zappy.h"
#include	"player.h"

void	server_pnw(t_zs *zs, t_zc *zc, void *server)
{
  t_iterator it;
  t_player *player;
  t_pnw pnw;

  iterator_ctor(&it, ((t_server *)server)->players, IT_DATA);
  while ((player = iterator_current(&it)))
    {
      pnw.uid = zc_get_uid(player->zc);
      pnw.position.x = player->x;
      pnw.position.y = player->y;
      pnw.orientation = player->direction;
      pnw.level = player->level;
      pnw.team_name = player->team_name;
      zs_send_cmd_pnw(zs, zc, &pnw);
      iterator_next(&it);
    }
}
