/*
** player_action_left.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:47:59 2014 damien sauvalle
** Last update Sun Jul 13 03:08:20 2014 damien sauvalle
*/

#include	"player.h"
#include	"player_action.h"
#include	"zappy.h"

void	player_action_left(t_zc *zc, void *data)
{
  t_bundle *bundle;

  (void)zc;
  bundle = (t_bundle *)data;
  if (bundle->player->direction == ORIENTATION_NORTH)
    bundle->player->direction = ORIENTATION_WEST;
  else
    bundle->player->direction--;
  server_send_ppo_all_graphic(bundle);
  zs_send_ok(bundle->server->zs, bundle->player->zc);
}
