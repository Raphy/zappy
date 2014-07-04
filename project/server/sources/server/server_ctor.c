/*
** server_ctor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 14:26:41 2014 damien sauvalle
** Last update Thu Jul  3 19:27:19 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"
#include	"my.h"

int	server_ctor(t_server *server, t_arg *arg)
{
  int	i;
  int	j;

  /*
  ** Norme
  */


  if ((server->map = malloc(sizeof(t_inventory*) * arg->x_world)) == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < arg->x_world)
    {
      if ((server->map[i] = malloc(sizeof(t_inventory) * arg->y_world)) == NULL)
	return (RET_FAILURE);
      i++;
    }
  if ((server->players = list_new(NULL)) == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < arg->x_world)
    {
      j = 0;
      while (j < arg->y_world)
	{
	  if (inventory_ctor(&(server->map[i][j])) == RET_FAILURE)
	    return (RET_FAILURE);
	  j++;
	}
      i++;
    }
  return (RET_SUCCESS);
}
