/*
** arg_parse_y_world.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:05:15 2014 damien sauvalle
** Last update Tue Jul  1 16:57:20 2014 damien sauvalle
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"arg.h"
#include	"my.h"

int	arg_parse_y_world(char **av, t_arg *arg, int opt)
{
  if (my_str_is_numeric(av[opt]) == false)
    {
      fprintf(stderr, "Y world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->y_world = atoi(av[opt]);
  if (arg->y_world <= 0)
    {
      fprintf(stderr, "Y world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  return (4);
}
