/*
** player_set_level.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:20:35 2014 damien sauvalle
** Last update Mon Jun 30 17:21:42 2014 damien sauvalle
*/

#include        "player.h"
#include	"zappy.h"
#include	"my.h"

void	player_set_level(t_player *player, int value)
{
  player->level = value;
}
