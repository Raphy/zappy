/*
** arg_parse_port.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:01:35 2014 damien sauvalle
** Last update Sun Jun 29 03:01:59 2014 damien sauvalle
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"server.h"
#include	"zappy.h"

int	arg_parse_port(char *av, t_arg *arg)
{
  if (check_int(av) == RET_FAILURE)
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
