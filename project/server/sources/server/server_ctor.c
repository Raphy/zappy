/*
** server_ctor.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 14:26:41 2014 damien sauvalle
** Last update Thu Jul 10 18:22:30 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"
#include	"my.h"
#include	"player.h"

static int	init_default(t_server *server, t_arg *arg)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (i < arg->x_world)
    {
      j = 0;
      while (j < arg->y_world)
	{
	  if (inventory_ctor(&(server->map[i][j].inventory)) == RET_FAILURE)
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
  unsigned int	i;

  y = arg->y_world;
  if ((server->map = malloc(sizeof(t_case *) * arg->x_world)) == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < arg->x_world)
    {
      if ((server->map[i] = malloc(sizeof(t_case) * y)) == NULL)
	return (RET_FAILURE);
      i++;
    }
  return (RET_SUCCESS);
}

int	server_ctor(t_server *server, t_arg *arg)
{
  if ((alloc_map(server, arg) == RET_FAILURE) ||
      ((server->players = list_new(&player_delete)) == NULL) ||
      ((server->events = list_new(NULL)) == NULL) ||
      ((server->eggs = list_new(NULL)) == NULL) ||
      ((server->graphic = list_new(&graphic_delete)) == NULL) ||
      ((server->remote = list_new(&remote_delete)) == NULL) ||
      (init_default(server, arg) == RET_FAILURE))
    return (RET_FAILURE);
  server->arg = arg;
  return (RET_SUCCESS);
}
