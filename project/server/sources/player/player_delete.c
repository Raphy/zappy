/*
** player_delete.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 02:40:44 2014 damien sauvalle
** Last update Thu Jul 10 02:42:03 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "my.h"
#include        "player.h"
#include        "server.h"

void	player_delete(t_player *player)
{
  player_dtor(player);
  free(player);
}
