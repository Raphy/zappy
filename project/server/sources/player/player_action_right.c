/*
** player_action_right.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:53:40 2014 damien sauvalle
** Last update Sat Jul 12 03:33:16 2014 damien sauvalle
*/

#include	"player.h"
#include	"zappy.h"

void	player_action_right(t_player *player, void *data)
{
  (void)data;
  if (player->direction == ORIENTATION_WEST)
    player->direction = ORIENTATION_NORTH;
  else
    player->direction++;
}
