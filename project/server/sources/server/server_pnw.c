/*
** server_pnw.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 01:55:54 2014 damien sauvalle
** Last update Sat Jul 12 21:56:34 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"
#include	"player.h"

void		server_pnw(t_zs *zs, t_zc *zc, void *data)
{
  t_pnw		pnw;
  t_player	*player;

  player = (t_player *)data;
  pnw.uid = zc_get_uid(player->zc);
  pnw.position.x = player->x;
  pnw.position.y = player->y;
  pnw.orientation = player->direction;
  pnw.level = player->level;
  pnw.team_name = player->team_name;
  zs_send_cmd_pnw(zs, zc, &pnw);
}
