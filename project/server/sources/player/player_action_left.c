/*
** player_action_left.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:47:59 2014 damien sauvalle
** Last update Wed Jul  9 15:15:53 2014 damien sauvalle
*/

#include	"player.h"

void	player_action_left(t_player *player, void *data)
{
  (void)data;
  if (player->direction == DIRECTION_NORTH)
    player->direction = DIRECTION_WEST;
  else
    player->direction = DIRECTION_WEST;
}
