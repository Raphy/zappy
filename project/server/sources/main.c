/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Fri Jun 27 23:18:41 2014 damien sauvalle
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

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

static void	cc_handler(t_zs *this, t_zc *zc, void *data)
{
  printf("hook client connected! fd:%d\n", zc->socket->fd);
}

static void	cd_handler(t_zs *this, t_zc *zc, void *data)
{
  printf("hook client disconnected! fd:%d\n", zc->socket->fd);
}

static void	to_handler(t_zs *this, void *data)
{
  printf("hook timeout!\n");
  zs_disable_timeout(this);
}

static void	errno_handler(t_zs *this, int err, const char *msg, void *data)
{
  fprintf(stderr, "[ERROR] ");
  if (err == 0 && msg == NULL)
    fprintf(stderr, "Unknown error");
  else if (err == 0 && msg != NULL)
    fprintf(stderr, "%s", msg);
  else if (err != 0 && msg == NULL)
    fprintf(stderr, "%s", strerror(err));
  else
    fprintf(stderr, "%s (%s)", strerror(err), msg);
  fprintf(stderr, "\n");
}

static void	init_server(t_zs *server)
{
  zs_set_timeout(server, 1, 500);
  zs_hook_timeout(server, &to_handler, NULL);
  zs_hook_client_connected(server, &cc_handler, NULL);
  zs_hook_client_disconnected(server, &cd_handler, NULL);
  zs_hook_errno(server, &errno_handler, NULL);
}

int		main(int argc, char **argv)
{
  t_zs		server;
  t_arg		arg;
  t_item *tmp;


  kikoo_header();

  get_arg(argc, argv, &arg);

  /* Faire le dump  des argument ICI */
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


  if (zs_ctor(&server, argc > 1 ? atoi(argv[1]) : 4242) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      zs_dtor(&server);
      return (EXIT_FAILURE);
    }
  printf("Running on port: %d\n", argc > 1 ? atoi(argv[1]) : 4242);
  init_server(&server);
  zs_main(&server);
  zs_dtor(&server);
  return (EXIT_FAILURE);
}
