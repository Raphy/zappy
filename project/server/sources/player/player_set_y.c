/*
** player_set_y.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:00:55 2014 damien sauvalle
** Last update Mon Jun 30 17:01:05 2014 damien sauvalle
*/

#include        "player.h"
#include	"zappy.h"
#include	"my.h"

void		player_set_y(t_player *player, int value)
{
  player->y = value;
}
