/*
** serveur_dtor.c for zappy in /home/damien/zappy/project/server/sources/serveur
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Wed Jul  2 17:49:08 2014 damien sauvalle
** Last update Wed Jul  2 21:22:41 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"serveur.h"

void	serveur_dtor(t_serveur *serveur, t_arg *arg)
{
  int	i;

  i = 0;
  while (i < arg->x_world)
    {
      free(serveur->map[i]);
      i++;
    }

  /*
  **  Penser a Vider les players !!
  */

  free(serveur->map);
  list_delete(serveur->players);
}
