/*
** player_set_x.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 16:59:28 2014 damien sauvalle
** Last update Mon Jun 30 17:00:25 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"my.h"

void		player_set_x(t_player *player, int value)
{
  player->x = value;
}
