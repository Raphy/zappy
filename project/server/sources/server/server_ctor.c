/*
** server_ctor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 14:26:41 2014 damien sauvalle
** Last update Fri Jul  4 15:43:39 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"
#include	"my.h"

static int	init_default(t_server *server, t_arg *arg)
{
  int		i;
  int		j;

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

static int	alloc_map(t_server *server, t_arg *arg)
{
  int		y;
  int		i;

  y = arg->y_world;
  if ((server->map = malloc(sizeof(t_inventory*) * arg->x_world)) == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < arg->x_world)
    {
      if ((server->map[i] = malloc(sizeof(t_inventory) * y)) == NULL)
	return (RET_FAILURE);
      i++;
    }
  return (RET_SUCCESS);
}

int	server_ctor(t_server *server, t_arg *arg)
{
  if ((alloc_map(server, arg) == RET_FAILURE) ||
      ((server->players = list_new(NULL)) == NULL) ||
      (init_default(server, arg) == RET_FAILURE))
    return (RET_FAILURE);
  return (RET_SUCCESS);
}
