/*
** player_get_level.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:21:57 2014 damien sauvalle
** Last update Mon Jun 30 17:23:36 2014 damien sauvalle
*/

#include        "player.h"
#include	"my.h"
#include	"zappy.h"

int player_get_level(t_player *player)
{
  return (player->level);
}
