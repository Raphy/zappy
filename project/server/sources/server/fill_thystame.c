/*
** fill_thystane.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul  4 14:24:40 2014 damien sauvalle
** Last update Thu Jul 10 20:08:59 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"

void	fill_thystane(t_case **map, t_arg *arg, int v)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  while (i < v)
    {
      x = rand()%arg->x_world;
      y = rand()%arg->y_world;
      if (map[y][x].inventory.thystame < 250)
	map[y][x].inventory.thystame += 1;
      i++;
    }
}
