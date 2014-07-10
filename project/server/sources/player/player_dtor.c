/*
** player_dtor.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 16:50:04 2014 damien sauvalle
** Last update Thu Jul 10 14:22:03 2014 damien sauvalle
*/

#include        "player.h"
#include	"zappy.h"
#include	"my.h"

void		player_dtor(t_player *player)
{
  if (player->team_name != NULL)
    free(player->team_name);
}
