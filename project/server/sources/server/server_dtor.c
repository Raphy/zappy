/*
** server_dtor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 17:49:08 2014 damien sauvalle
** Last update Thu Jul  3 19:27:43 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"

void	server_dtor(t_server *server, t_arg *arg)
{
  int	i;

  i = 0;
  while (i < arg->x_world)
    {
      free(server->map[i]);
      i++;
    }

  /*
  **  Penser a Vider les players !!
  */

  free(server->map);
  list_delete(server->players);
}
