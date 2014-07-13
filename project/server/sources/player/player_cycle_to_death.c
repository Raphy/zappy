/*
** player_action_fork.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 17:51:39 2014 damien sauvalle
** Last update Sat Jul  5 17:51:45 2014 damien sauvalle
*/

#include	"player.h"
#include "bundle.h"
#include "event.h"

void player_cycle_to_death(t_zc *zc, void *data)
{
  t_bundle        * bundle;
  t_scratch_event   bundle_event;
  
  bundle = (t_bundle*)data;
  if (bundle->player->inventory.food == 0)
  {
    if (zc != NULL)
    {
      /* CHECk CLIENT DISCONNECTED AND REMOVE T_PLAYER */
      zs_send_death(bundle->server->zs, zc);
      zc_disconnect(zc);
    }
    printf("Player dead...");
  }
  else
  {
    bundle->player->inventory.food--;
    bundle_event.action = &player_cycle_to_death;
    bundle_event.cycle = 126;
    printf("Player dying... [%d]", bundle->player->inventory.food);
    event_create_from_scratch(&bundle_event, (t_bundle*)data); 
  }
}
