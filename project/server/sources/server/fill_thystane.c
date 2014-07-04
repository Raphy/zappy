/*
** fill_thystane.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul  4 14:24:40 2014 damien sauvalle
** Last update Fri Jul  4 14:25:15 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"


void	fill_thystane(t_inventory **map, t_arg *arg, int v)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < v)
    {
      x = rand()%arg->x_world;
      y = rand()%arg->y_world;
      if (map[x][y].thystane < 250)
	map[x][y].thystane += 1;
      i++;
    }
}
