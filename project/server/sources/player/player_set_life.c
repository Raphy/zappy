/*
** player_set_life.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:24:43 2014 damien sauvalle
** Last update Mon Jun 30 17:29:21 2014 damien sauvalle
*/

#include        "player.h"
#include	"inventory.h"
#include	"zappy.h"
#include	"my.h"

int	player_set_life(t_player *player)
{
  player->life = inventory_get_food(&player->inventory); /* 126; add 1/t */
  return (RET_SUCCESS);
}
