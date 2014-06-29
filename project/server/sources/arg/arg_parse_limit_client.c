/*
** arg_parse_limit_client.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:05:51 2014 damien sauvalle
** Last update Sun Jun 29 03:28:59 2014 damien sauvalle
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"server.h"
#include	"zappy.h"

int	arg_parse_limit_client(char *av, t_arg *arg)
{
  if (check_int(av) == RET_FAILURE)
    {
      fprintf(stderr, "limit client must be numeric and positif\n");
      return (RET_FAILURE);
    }
  arg->limit_client = atoi(av);
  if (arg->limit_client <= 0)
    {
      fprintf(stderr, "limit client must be numeric and positif\n");
      return (RET_FAILURE);
    }
  return (16);
}
