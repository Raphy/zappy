/*
** player_new.c for zappy in /home/damien/zappy/project/server/sources/player
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 02:17:37 2014 damien sauvalle
** Last update Thu Jul 10 14:23:22 2014 damien sauvalle
*/

#include        <stdlib.h>
#include        "my.h"
#include        "player.h"
#include        "server.h"

t_player	*player_new(t_server *server, t_zc *zc, const char *team)
{
  t_player	*new;

  if ((new = malloc(sizeof(t_player))) == NULL)
    return (NULL);
  if (player_ctor(new, server, zc, team) == RET_FAILURE)
    {
      player_delete(new);
      return (NULL);
    }
  list_enqueue(&(server->map[new->y][new->x].players), new);
  return (new);
}
