/*
** player_get_life.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:29:33 2014 damien sauvalle
** Last update Mon Jun 30 17:30:32 2014 damien sauvalle
*/

#include        "player.h"
#include	"my.h"
#include	"zappy.h"

unsigned int player_get_life(t_player *player)
{
  return (player->life);
}
