/*
** arg_parse_port.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:01:35 2014 damien sauvalle
** Last update Sun Jun 29 17:31:16 2014 raphael defreitas
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"arg.h"
#include	"my.h"

int	arg_parse_port(char *av, t_arg *arg)
{
  if (my_str_is_numeric(av) == false)
    {
      fprintf(stderr, "The port is invalid\n");
      return (RET_FAILURE);
    }
  arg->port = atoi(av);
  if (arg->port <= 0 || arg->port > 65536)
    {
      fprintf(stderr, "The port is invalid\n");
      return (RET_FAILURE);
    }
  return (2);
}
