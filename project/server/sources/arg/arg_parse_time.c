/*
** arg_parse_time.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:07:15 2014 damien sauvalle
** Last update Tue Jul  1 17:01:12 2014 damien sauvalle
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"arg.h"
#include	"my.h"

int	arg_parse_time(char **av, t_arg *arg, int opt)
{
  if (my_str_is_numeric(av[opt]) == false)
    {
      fprintf(stderr, "Time must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->time = atoi(av[opt]);
  if (arg->time <= 0)
    {
      fprintf(stderr, "Time must be numeric and positif\n");
      return (0);
    }
  return (32);
}
