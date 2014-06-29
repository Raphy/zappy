/*
** arg_parse_y_world.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:05:15 2014 damien sauvalle
** Last update Sun Jun 29 17:32:36 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"arg.h"
#include	"my.h"

int	arg_parse_y_world(char *av, t_arg *arg)
{
  if (my_str_is_numeric(av) == false)
    {
      fprintf(stderr, "Y world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->y_world = atoi(av);
  if (arg->y_world <= 0)
    {
      fprintf(stderr, "Y world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  return (4);
}
