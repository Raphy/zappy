/*
** arg_parse_x_world.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:04:42 2014 damien sauvalle
** Last update Sun Jul 13 11:27:11 2014 damien sauvalle
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"arg.h"
#include	"my.h"

int	arg_parse_x_world(char **av, t_arg *arg, int opt)
{
  if (my_str_is_numeric(av[opt]) == false)
    {
      fprintf(stderr, "X world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->x_world = atoi(av[opt]);
  if (arg->x_world <= 0)
    {
      fprintf(stderr, "X world must be numeric and positif\n");
      return (RET_FAILURE);
    }
  return (8);
}
