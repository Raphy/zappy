/*
** player_set_life.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:24:43 2014 damien sauvalle
** Last update Mon Jun 30 17:29:21 2014 damien sauvalle
*/

#include        <assert.h>
#include        "player.h"
#include	"inventory.h"
#include	"zappy.h"
#include	"my.h"
#include "player_action.h"

int	player_set_life(t_player *player)
{
  if (player != NULL)
  {
    player->inventory.food = 10;
    return (RET_SUCCESS);
  }
  return (RET_FAILURE);
}
