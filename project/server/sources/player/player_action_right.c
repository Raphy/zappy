/*
** player_action_right.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:53:40 2014 damien sauvalle
** Last update Wed Jul  9 15:14:25 2014 damien sauvalle
*/

#include	"player.h"

void	player_action_right(t_player *player, void *data)
{
  if (player->direction == DIRECTION_WEST)
    player->direction = DIRECTION_NORTH;
  else
    player->direction++;
}
