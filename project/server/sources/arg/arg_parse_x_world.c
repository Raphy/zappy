/*
** arg_parse_x_world.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:04:42 2014 damien sauvalle
** Last update Sun Jun 29 03:31:16 2014 damien sauvalle
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"server.h"
#include	"zappy.h"

int	arg_parse_x_world(char *av, t_arg *arg)
{
  if (check_int(av) == RET_FAILURE)
    {
      fprintf(stderr, "X world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->x_world = atoi(av);
  if (arg->x_world <= 0)
    {
      fprintf(stderr, "X world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  return (8);
}
