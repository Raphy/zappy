/*
** player_action_incantation.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 17:51:21 2014 damien sauvalle
** Last update Sat Jul  5 17:51:28 2014 damien sauvalle
*/
#include        "bundle.h"
#include	"player.h"
#include        "handlers.h"

void player_action_incantation(t_zc *zc, void *data)
{
  t_bundle *datas;
  t_case *current;
  
  if (data == NULL)
      return;
  datas = (t_bundle *)data;
  current = &(datas->server->map[datas->player->y][datas->player->x]);
  if (verify_elevation_condition(datas->player, current) == RET_FAILURE)
  {
      zs_send_ko(datas->server->zs, zc);
      return;
  }
  datas->player->etat = NORMAL;
  datas->player->level++;
}
