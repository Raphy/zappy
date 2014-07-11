/*
** arg_parse.c for zappy in /home/damien/zappy/project/server/sources
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 19:00:24 2014 damien sauvalle
** Last update Fri Jul 11 23:18:57 2014 damien sauvalle
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"arg.h"
#include	"my.h"

static int	usage(char *progname)
{
  fprintf(stderr, "Usage: %s -p port -x x_world] -y y_world \
 -c limit_clients -t time -n team_name_1 team_name_2 ...\n", progname);
  return (RET_FAILURE);
}

static void     fill_map(t_parser_map *map)
{
  int           i;

  i = 0;
  map[i].index = 'p';
  map[i++].function = &arg_parse_port;
  map[i].index = 'x';
  map[i++].function = &arg_parse_x_world;
  map[i].index = 'y';
  map[i++].function = &arg_parse_y_world;
  map[i].index = 'n';
  map[i++].function = &arg_parse_team_names;
  map[i].index = 'c';
  map[i++].function = &arg_parse_limit_client;
  map[i].index = 't';
  map[i++].function = &arg_parse_time;
}

static int	process(t_arg *arg, int ac, char **av)
{
  t_parser_map  map[6];
  int		opt;
  int		ret;
  int		i;

  ret = 0;
  fill_map(map);
  while ((opt = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
    {
      if (opt == '?' || opt == ':')
	return (usage(av[0]));
      i = 0;
      while (i < 6)
	{
	  if (opt == map[i].index)
	    ret += map[i].function(av, arg, optind - 1);
	  i++;
	}
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
