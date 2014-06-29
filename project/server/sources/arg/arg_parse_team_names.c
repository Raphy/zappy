/*
** arg_parse_team_names.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:08:11 2014 damien sauvalle
** Last update Sun Jun 29 03:28:08 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	"server.h"
#include	"zappy.h"

int	arg_parse_team_names(int ac, char **av, t_arg *arg, int op)
{
  int	i;

  i = op;
  while (i < ac && *av[i] != '-')
    {
      list_push(arg->team_names, av[i]);
      i++;
    }
  return (64);
}
