/*
** add_player.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Tue Jul  8 14:26:41 2014 damien sauvalle
** Last update Tue Jul  8 14:30:39 2014 damien sauvalle
*/

#include	"server.h"

void	add_player(t_server *server, t_player *player)
{
  if (player != NULL)
    list_push(server->players, player);
}
