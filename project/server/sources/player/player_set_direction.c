/*
** player_set_direction.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 16:54:28 2014 damien sauvalle
** Last update Sat Jul 12 10:37:42 2014 damien sauvalle
*/

#include        <assert.h>
#include        "player.h"
#include	"zappy.h"
#include	"my.h"

void		player_set_direction(t_player *player, t_orientation direction)
{
  player->direction = direction;
}
