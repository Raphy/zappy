/*
** dump_map.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 15:43:50 2014 damien sauvalle
** Last update Thu Jul 10 20:08:15 2014 damien sauvalle
*/

#include	<stdio.h>
#include	"server.h"

void		dump_map(t_server *server, t_arg *arg)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (i < arg->x_world)
    {
      j = 0;
      while (j < arg->y_world)
	{
	  printf("map[%d][%d]\n", i, j);
	  printf("\t linemate : %d\n", server->map[i][j].inventory.linemate);
	  printf("\t deraumere : %d\n", server->map[i][j].inventory.deraumere);
	  printf("\t sibur : %d\n", server->map[i][j].inventory.sibur);
	  printf("\t menduane : %d\n", server->map[i][j].inventory.mendiane);
	  printf("\t phirad : %d\n", server->map[i][j].inventory.phiras);
	  printf("\t thystame : %d\n", server->map[i][j].inventory.thystame);
	  printf("\t food : %d\n\n", server->map[i][j].inventory.food);
	  j++;
	}
      i++;
    }
}
