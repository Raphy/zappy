/*
** serveur_ctor.c for zappy in /home/damien/zappy/project/server/sources/serveur
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 14:26:41 2014 damien sauvalle
** Last update Wed Jul  2 21:21:23 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"serveur.h"
#include	"my.h"

int	serveur_ctor(t_serveur *serveur, t_arg *arg)
{
  int	i;
  int	j;

  if ((serveur->map = malloc(sizeof(t_inventory*) * arg->x_world)) == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < arg->x_world)
    {
      if ((serveur->map[i] = malloc(sizeof(t_inventory) * arg->y_world)) == NULL)
	return (RET_FAILURE);
      i++;
    }
  if ((serveur->players = list_new(NULL)) == NULL)
    return (RET_FAILURE);
  i = 0;
  while (i < arg->x_world)
    {
      j = 0;
      while (j < arg->y_world)
	{
	  if (inventory_ctor(&(serveur->map[i][j])) == RET_FAILURE)
	    return (RET_FAILURE);
	  j++;
	}
      i++;
    }
  return (RET_SUCCESS);
}
