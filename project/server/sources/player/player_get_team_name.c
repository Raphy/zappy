/*
** player_get_team_name.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Mon Jun 30 17:19:18 2014 damien sauvalle
** Last update Mon Jun 30 17:20:15 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"my.h"

char	*player_get_team_name(t_player *player)
{
  return (player->team_name);
}
