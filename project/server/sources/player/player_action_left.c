/*
** player_action_left.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 16:47:59 2014 damien sauvalle
** Last update Sat Jul 12 02:20:41 2014 damien sauvalle
*/

#include	"player.h"

void	player_action_left(t_player *player, void *data)
{
  printf("Player action 'left' called");
  (void)data;
  if (player->direction == ORIENTATION_NORTH)
    player->direction = ORIENTATION_WEST;
  else
    player->direction--;
}
