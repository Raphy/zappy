/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Sun Jun 29 03:40:58 2014 damien sauvalle
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"handlers.h"
#include	"list.h"
#include	"zappy.h"
#include	"server.h"

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

static void	print_info(t_arg arg)
{
  t_item	*tmp;

  printf("Running on port : %d\n", arg.port);
  printf("X_World : %d\n", arg.x_world);
  printf("Y_World : %d\n", arg.y_world);
  printf("Limit Client : %d\n", arg.limit_client);
  printf("Time : %d\n", arg.time);
  tmp = arg.team_names->front;
  printf("Team name :");
  while (tmp)
    {
      printf(" \"%s\"", (char*)tmp->data);
      tmp = tmp->next;
    }
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
      zs_dtor(&zs);
      arg_dtor(&arg);
      return (EXIT_FAILURE);
    }
  print_info(arg);
  set_server_handlers(&zs, NULL);
  zs_main(&zs);
  zs_dtor(&zs);
  arg_dtor(&arg);
  return (EXIT_SUCCESS);
}
