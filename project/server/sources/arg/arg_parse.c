/*
** arg_parse.c for zappy in /home/damien/zappy/project/server/sources
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 19:00:24 2014 damien sauvalle
** Last update Sun Jun 29 02:41:49 2014 damien sauvalle
*/

#define		_GNU_SOURCE
#include	<unistd.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"server.h"
#include	"zappy.h"

int	check_int(char *av)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (isdigit(av[i]) == 0)
	return (RET_FAILURE);
      i++;
    }
  return (RET_SUCCESS);
}

static int	usage(char *av)
{
  fprintf(stderr, "Usage: %s [-p port] [-x x_world] [-y y_world] \
 [-c limit_clients] [-t time] [-n team_name_1 team_name_2 ...]\n", av);
  return (RET_FAILURE);
}

int	arg_parse(t_arg *arg, int ac, char **av)
{
  int	opt;
  int	ret;

  ret = 0;
  while ((opt = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
    {
      if (opt == 'p')
	ret += arg_parse_port(av[optind - 1], arg);
      else if (opt == 'x')
	ret += arg_parse_x_world(av[optind - 1], arg);
      else if (opt == 'y')
	ret += arg_parse_y_world(av[optind - 1], arg);
      else if (opt == 'n')
	ret += arg_parse_team_names(ac, av, arg, optind - 1);
      else if (opt == 'c')
	ret += arg_parse_limit_client(av[optind - 1], arg);
      else if (opt == 't')
	ret += arg_parse_time(av[optind - 1], arg);
      else if (opt == '?' || opt == ':')
	return (usage(av[0]));
    }
  if (ret != 126)
    return (usage(av[0]));
  return (RET_SUCCESS);
}
