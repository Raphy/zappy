/*
** player_get_y.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:01:36 2014 damien sauvalle
** Last update Mon Jun 30 17:02:59 2014 damien sauvalle
*/

#include        <assert.h>
#include        "player.h"
#include	"zappy.h"
#include	"my.h"

int	player_get_y(t_player *player)
{
  assert(player != NULL);
  return (player->y);
}
