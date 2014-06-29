/*
** arg_parse_time.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:07:15 2014 damien sauvalle
** Last update Sun Jun 29 03:30:30 2014 damien sauvalle
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"zappy.h"
#include	"server.h"

int	arg_parse_time(char *av, t_arg *arg)
{
  if (check_int(av) == RET_FAILURE)
    {
      fprintf(stderr, "Time must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->time = atoi(av);
  if (arg->time <= 0)
    {
      fprintf(stderr, "Time must be numeric and positif\n");
      return (0);
    }
  return (32);
}
