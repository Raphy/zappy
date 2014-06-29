/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Sun Jun 29 02:32:20 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"handlers.h"
#include	"list.h"
#include	"zappy.h"

static void	kikoo_header(void)
{
  printf(" ______                             _____ _ _            _\n");
  printf(" ___  /                            / ____| (_)          | |\n");
  printf("   / / __ _ _ __  _ __  _   _     | |    | |_  ___ _ __ | |\n");
  printf("  / / / _` | '_ \\| '_ \\| | | |    | |    | | |/ _ \\ '_ \\| __|\n");
  printf(" / /_| (_| | |_) | |_) | |_| |    | |____| | |  __/ | | | |_\n");
  printf(" _____\\__,_| .__/| .__/ \\__, |     \\_____|_|_|\\___|_| |_|\\__|\n");
  printf("           | |   | |     __/ |\n");
  printf("           |_|   |_|    |___/\n");
  printf("\n\n");
}

int		main(int argc, char **argv)
{
  t_zc		zc;

  kikoo_header();

  if (argc != 3)
    exit(printf("Usage: %s [host] [port]\n", argv[0]));
  if (zc_ctor(&zc) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      zc_dtor(&zc);
      return (EXIT_FAILURE);
    }
  printf("Connecting to %s %d...\n", argv[1], atoi(argv[2]));
  if (zc_connect(&zc, argv[1], atoi(argv[2])) == RET_FAILURE)
    {
      printf("The host %s:%d is not reachable!\n", argv[1], atoi(argv[2]));
      zc_dtor(&zc);
      return (EXIT_FAILURE);
    }
  set_handlers(&zc, NULL);
  zc_main(&zc);
  zc_dtor(&zc);
  return (EXIT_SUCCESS);
}
