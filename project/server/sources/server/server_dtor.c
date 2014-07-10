/*
** server_dtor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 17:49:08 2014 damien sauvalle
** Last update Thu Jul 10 01:39:03 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"

void		server_dtor(t_server *server)
{
  unsigned int	i;

  arg_dtor(server->arg);
  i = 0;
  while (i < server->arg->x_world)
    {
      free(server->map[i]);
      i++;
    }
  /*
  **  Penser a Vider les players !!
  ** + Eggs
  */
  free(server->map);
  list_delete(server->players);
}
