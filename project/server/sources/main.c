/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Mon May 12 17:10:30 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"zappy.h"

static void	kikoo_header(void)
{
  printf("+---------------------------------+\n");
  printf("|    ______ _ _ __  _ __  _   _   |\n");
  printf("|   |_  / _` | '_ \\| '_ \\| | | |  |\n");
  printf("|    / / (_| | |_) | |_) | |_| |  |\n");
  printf("|   /___\\__,_| .__/| .__/ \\__, |  |\n");
  printf("|            | |   | |     __/ |  |\n");
  printf("|            |_|   |_|    |___/   |\n");
  printf("|                                 |\n");
  printf("+---------------------------------+\n");
}

int		main(int argc, char **argv)
{
  t_zs		server;

  kikoo_header();
  if (zs_ctor(&server, argc > 1 ? atoi(argv[1]) : 4242) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      zs_dtor(&server);
      return (EXIT_FAILURE);
    }
  printf("Running on port: %d\n", argc > 1 ? atoi(argv[1]) : 4242);
  zs_dtor(&server);
  return (EXIT_SUCCESS);
}
