/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Sun Jun 29 17:40:19 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"arg.h"
#include	"handlers.h"
#include	"list.h"
#include	"zappy.h"

static void	kikoo_header(void)
{
  printf(" ______                             _____\n");
  printf(" ___  /                            / ____|\n");
  printf("   / / __ _ _ __  _ __  _   _     | (___   ___ _ ____   _____ _ __\n");
  printf("  / / / _` | '_ \\| '_ \\| | | |     \\___ \\ / _ \\ '__\\ \\ / /");
  printf("  _\\ __|\n");
  printf(" / /_| (_| | |_) | |_) | |_| |     ____) |  __/ |   \\ V /  __/ |\n");
  printf(" _____\\__,_| .__/| .__/ \\__, |    |_____/ \\___|_|    \\_/ \\");
  printf("___|_|\n");
  printf("           | |   | |     __/ |\n");
  printf("           |_|   |_|    |___/\n");
  printf("\n\n");
}

int		main(int argc, char **argv)
{
  t_zs		zs;
  t_arg		arg;

  kikoo_header();
  if (arg_ctor(&arg) == RET_ERROR ||
      arg_parse(&arg, argc, argv) == RET_FAILURE)
    {
      arg_dtor(&arg);
      return (EXIT_FAILURE);
    }
  if (zs_ctor(&zs, arg.port, arg.team_names) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      arg_dtor(&arg);
      zs_dtor(&zs);
      return (EXIT_FAILURE);
    }
  arg_dump(&arg);
  set_server_handlers(&zs, NULL);
  zs_main(&zs);
  zs_dtor(&zs);
  arg_dtor(&arg);
  return (EXIT_SUCCESS);
}
