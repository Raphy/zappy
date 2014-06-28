/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Sat Jun 28 01:58:22 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"handlers.h"
#include	"zappy.h"
#include	"server.h"

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
  t_zs		zs;
  t_arg		arg;
  t_item *tmp;

  kikoo_header();
  get_arg(argc, argv, &arg);

  /* Debut Debug */
  printf("PORT %d\n", arg.port);
  printf("X_WORLD %d\n", arg.x_world);
  printf("Y_WORLD %d\n", arg.y_world);

  printf("LIMIT_CLIENT %d\n", arg.limit_client);
  printf("TIME %d\n", arg.time);

  tmp = arg.team_names->front;

  while (tmp)
    {
      printf("NAME %s\n",(char*)tmp->data);
      tmp = tmp->next;
    }
  /* Fin Debug */



  if (zs_ctor(&zs, arg.port, arg.team_names) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      zs_dtor(&zs);
      return (EXIT_FAILURE);
    }
  printf("Running on port: %d\n", arg.port);
  set_server_handlers(&zs, NULL);
  zs_main(&zs);
  zs_dtor(&zs);
  return (EXIT_FAILURE);
}
