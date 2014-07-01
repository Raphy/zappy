/*
** arg_parse.c for zappy in /home/damien/zappy/project/server/sources
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 19:00:24 2014 damien sauvalle
** Last update Sun Jun 29 17:23:55 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"arg.h"
#include	"my.h"

static int	usage(char *progname)
{
  fprintf(stderr, "Usage: %s [-p port] [-x x_world] [-y y_world] \
 [-c limit_clients] [-t time] [-n team_name_1 team_name_2 ...]\n", progname);
  return (RET_FAILURE);
}

void            test(void) 
{
  
}

static void     fill_map(t_parser_map *map)
{
  int           i;
  
  i = 0;
  map[i++] = (t_parser_map){'p', &test};
  map[i++] = (t_parser_map){'x', &test};
  map[i++] = (t_parser_map){'y', &test};
  map[i++] = (t_parser_map){'n', &test};
  map[i++] = (t_parser_map){'c', &test};
  map[i++] = (t_parser_map){'t', &test};
}

static int	process(t_arg *arg, int ac, char **av)
{
  t_parser_map  map[6];
  int		opt;
  int		ret;

  ret = 0;
  fill_map(map);
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
  return (ret);
}

int		arg_parse(t_arg *arg, int ac, char **av)
{
  int		ret;

  if (arg == NULL)
    return (RET_FAILURE);
  ret = process(arg, ac, av);
  if (ret != 126)
    return (usage(av[0]));
  return (RET_SUCCESS);
}
