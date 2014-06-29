/*
** arg_parse_team_names.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:08:11 2014 damien sauvalle
** Last update Sun Jun 29 17:31:58 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"arg.h"
#include	"list.h"

int	arg_parse_team_names(int ac, char **av, t_arg *arg, int op)
{
  int	i;

  i = op;
  while (i < ac && *av[i] != '-')
    {
      if (list_push(arg->team_names, av[i]) == RET_ERROR)
	return (RET_ERROR);
      i++;
    }
  return (64);
}
