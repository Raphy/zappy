/*
** fill_linemate.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 23:23:35 2014 damien sauvalle
** Last update Fri Jul  4 14:09:53 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"

void	fill_linemate(t_inventory **map, t_arg *arg, int v)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < v)
    {
      x = rand()%arg->x_world;
      y = rand()%arg->y_world;
      if (map[x][y].linemate < 250)
	map[x][y].linemate += 1;
      i++;
    }
}
