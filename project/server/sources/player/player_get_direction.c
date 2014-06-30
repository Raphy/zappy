/*
** player_get_direction.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 16:56:20 2014 damien sauvalle
** Last update Mon Jun 30 16:58:58 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"my.h"

t_direction	player_get_direction(t_player *player)
{
  return (player->direction);
}
