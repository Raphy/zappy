/*
** arg_parse_team_names.c for zappy in /home/damien/zappy/project/server/sources/arg
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 01:08:11 2014 damien sauvalle
** Last update Sun Jul 13 11:26:27 2014 damien sauvalle
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"arg.h"
#include	"list.h"

int	arg_parse_team_names(char **av, t_arg *arg, int op)
{
  int	i;
  int	len;

  i = op;
  len = 0;
  while (av[i] && *av[i] != '-')
    {
      if (list_push(arg->team_names, av[i]) == RET_ERROR)
	return (RET_ERROR);
      len++;
      i++;
    }
  if (len < 2)
    {
      printf("You must create at least two teams\n");
      return (0);
    }
  return (64);
}
