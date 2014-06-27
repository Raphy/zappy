/*
** get_arg.c for zappy in /home/damien/zappy/project/server/sources
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jun 27 19:00:24 2014 damien sauvalle
** Last update Fri Jun 27 23:18:34 2014 damien sauvalle
*/

#define		_GNU_SOURCE
#include	<unistd.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"server.h"
#include	"zappy.h"

/* ret add */
int	p_opt(char **av, t_arg *arg)
{
  int	i;

  printf("-p Numero port : %s\n", av[optind - 1]); /* Debug */
  i = 0;
  while (av[optind - 1][i])
    {
      if (isdigit(av[optind - 1][i]) == 0)
	{
	  fprintf(stderr, "Bad port\n");
	  return (0);
	}
      i++;
    }
  arg->port = atoi(av[optind - 1]);
  return (1);
}

int	y_opt(char **av, t_arg *arg)
{
  int	i;

  printf("-y Y world : %s\n", av[optind - 1]); /* Debug */
  i = 0;
  while (av[optind - 1][i])
    {
      if (isdigit(av[optind - 1][i]) == 0)
	{
	  fprintf(stderr, "Bad Y World\n");
	  return (0);
	}
      i++;
    }
  arg->y_world = atoi(av[optind - 1]);
  return (1);
}

int	x_opt(char **av, t_arg *arg)
{
  int	i;

  printf("-x X world : %s\n", av[optind - 1]); /* Debug */
  i = 0;
  while (av[optind - 1][i])
    {
      if (isdigit(av[optind - 1][i]) == 0)
	{
	  fprintf(stderr, "Bad X World\n");
	  return (0);
	}
      i++;
    }
  arg->x_world = atoi(av[optind - 1]);
  return (1);
}

int	c_opt(char **av, t_arg *arg)
{
  int	i;

  printf("-c Nb by equipe : %s\n", av[optind - 1]); /* Debug */
  i = 0;
  while (av[optind - 1][i])
    {
      if (isdigit(av[optind - 1][i]) == 0)
	{
	  fprintf(stderr, "Bad Limit client\n");
	  return (0);
	}
      i++;
    }
  arg->limit_client = atoi(av[optind - 1]);
  return (1);
}

int	t_opt(char **av, t_arg *arg)
{
  int	i;

  printf("-t Time : %s\n", av[optind - 1]); /* Debug */
  i = 0;
  while (av[optind - 1][i])
    {
      if (isdigit(av[optind - 1][i]) == 0)
	{
	  fprintf(stderr, "Bad Time\n");
	  return (0);
	}
      i++;
    }
  arg->time = atoi(av[optind - 1]);
  return (1);
}

int n_opt(int ac, char **av, t_arg *arg)
{
  int i;

  arg->team_names = list_new(NULL);
  i = optind - 1;
  while (i < ac && *av[i] != '-')
    {
      list_push(arg->team_names, av[i]);
      i++;
    }
  return (1);
}

int	get_arg(int ac, char **av, t_arg *arg)
{
  int	opt;
  int	ret;

  ret = 0;
  while ((opt = getopt(ac, av, "p:x:y:n:c:t:")) != -1)
    {
      if (opt == 'p')
	ret += p_opt(av, arg);/* ok */
      else if (opt == 'x')
	ret += x_opt(av, arg);
      else if (opt == 'y')
	ret += y_opt(av, arg);
      else if (opt == 'n')
	ret += n_opt(ac, av, arg);
      else if (opt == 'c')
	ret += c_opt(av, arg);
      else if (opt == 't')
	ret += t_opt(av, arg);
      else
	fprintf(stderr, "Usage: %s \n",av[0]);
    }
  /*
    Check ret !!
   */
  return (0);
}
