/*
** generate_ressource.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 15:23:11 2014 damien sauvalle
** Last update Fri Jul  4 14:27:17 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"

static int	my_rand(int min, int max)
{
  return ((rand()%max - min) + min);
}

static void	define_density(unsigned int *tab, int size_map)
{
  tab[LINEMATE] = (size_map * my_rand(60, 85) ) / 100;
  tab[DERAUMERE] = (size_map * my_rand(50, 75)) / 100;
  tab[SIBUR] = (size_map * my_rand(40, 60)) / 100;
  tab[MENDIANE] = (size_map * my_rand(30, 50)) / 100;
  tab[PHIRAS] = (size_map * my_rand(10, 25)) / 100;
  tab[THYSTANE] = (size_map * my_rand(0, 10)) / 100;
  tab[FOOD] = (size_map * my_rand(0, 50)) / 100;
}

static void	set_fill(t_fill_map *fill)
{
  fill[LINEMATE].fill = &fill_linemate;
  fill[DERAUMERE].fill = &fill_deraumere;
  fill[SIBUR].fill = &fill_sibur;
  fill[MENDIANE].fill = &fill_mendiane;
  fill[PHIRAS].fill = &fill_phiras;
  fill[THYSTANE].fill = &fill_thystane;
  fill[FOOD].fill = &fill_food;
}

void		generate_ressource(t_server *server, t_arg *arg)
{
  unsigned int	tab[7];
  t_fill_map	fill[7];
  int		i;

  define_density(tab, arg->x_world * arg->y_world);
  set_fill(fill);
  i = 0;
  while (i < SIZE_INVENTORY)
    {
      fill[i].fill(server->map, arg, tab[i]);
      i++;
    }
}
