/*
** player_action_pick.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul  5 17:49:12 2014 damien sauvalle
** Last update Sun Jul 13 12:10:36 2014 damien sauvalle
*/

#include	<stdio.h>

#include	"player.h"

void	player_action_pick(t_player *player, void *data, char *c)
{
  (void)player;
  (void)data;

  printf("(############)---> YOLO SWAGG : %s\n", c);

}
