/*
** fill_phiras.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul  4 14:23:18 2014 damien sauvalle
** Last update Mon Jul  7 17:06:01 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"

void	fill_phiras(t_case **map, t_arg *arg, int v)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < v)
    {
      x = rand()%arg->x_world;
      y = rand()%arg->y_world;
      if (map[y][x].inventory.phiras < 250)
	map[y][x].inventory.phiras += 1;
      i++;
    }
}
