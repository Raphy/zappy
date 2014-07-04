/*
** dump_map.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 15:43:50 2014 damien sauvalle
** Last update Thu Jul  3 23:13:13 2014 damien sauvalle
*/

#include	<stdio.h>
#include	"server.h"

void	dump_map(t_server *server, t_arg *arg)
{
  int	i;
  int	j;

  i = 0;
  while (i < arg->x_world)
    {
      j = 0;
      while (j < arg->y_world)
	{
	  printf("map[%d][%d]\n", i, j);
	  printf("\t linemate : %d\n", server->map[i][j].linemate);
	  printf("\t deraumere : %d\n", server->map[i][j].deraumere);
	  printf("\t sibur : %d\n", server->map[i][j].sibur);
	  printf("\t menduane : %d\n", server->map[i][j].mendiane);
	  printf("\t phirad : %d\n", server->map[i][j].phiras);
	  printf("\t thystane : %d\n", server->map[i][j].thystane);
	  printf("\t food : %d\n\n", server->map[i][j].food);
	  j++;
	}
      i++;
    }
}
