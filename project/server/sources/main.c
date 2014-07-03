/*
** main.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Mon May 12 14:06:41 2014 raphael defreitas
** Last update Wed Jul  2 17:51:28 2014 damien sauvalle
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"arg.h"
#include	"handlers.h"
#include	"list.h"
#include	"zappy.h"
#include	"serveur.h"

static void	kikoo_header(void)
{
  printf(" ______                             _____\n");
  printf(" ___  /                            / ____|\n");
  printf("   / / __ _ _ __  _ __  _   _     | (___   ___ _ ____   _____ ___\n");
  printf("  / / / _` | '_ \\| '_ \\| | | |     \\___ \\ / _ \\ '__\\ \\ / /");
  printf("  _\\ __|\n");
  printf(" / /_| (_| | |_) | |_) | |_| |     ____) |  __/ |   \\ V /  __/ |\n");
  printf(" _____\\__,_| .__/| .__/ \\__, |    |_____/ \\___|_|    \\_/ \\");
  printf("___|_|\n");
  printf("           | |   | |     __/ |\n");
  printf("           |_|   |_|    |___/\n");
  printf("\n\n");
}

static int	init_zappy(t_zs *zs, t_arg *arg)
{
if (zs_ctor(zs, arg->port, arg->team_names) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      return (RET_FAILURE);
    }
 if (zs_set_rsa_keys(zs, "./keys/public.pem", "./keys/private.pem") ==
     RET_FAILURE)
   {
     fprintf(stderr, "+------------------------------------------+\n");
     fprintf(stderr, "| Initialization of RSA key pairing failed |\n");
     fprintf(stderr, "| The server won't accept remote client    |\n");
     fprintf(stderr, "+------------------------------------------+\n\n");
   }
 return (RET_SUCCESS);
}

static int return_arg_fail(t_arg *arg)
{
  arg_dtor(arg);
  return (EXIT_FAILURE);
}

static int return_zs_fail(t_zs *zs, t_arg *arg)
{
  arg_dtor(arg);
  zs_dtor(zs);
  return (EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
  t_zs		zs;
  t_arg		arg;
  t_serveur	serveur;

  kikoo_header();
  if (arg_ctor(&arg) == RET_ERROR ||
      arg_parse(&arg, argc, argv) == RET_FAILURE)
    return (return_arg_fail(&arg));
  if (init_zappy(&zs, &arg) == RET_FAILURE)
    return (return_zs_fail(&zs, &arg));
  arg_dump(&arg);
  set_server_handlers(&zs, NULL);

  serveur_ctor(&serveur, &arg);

  zs_main(&zs);

  serveur_dtor(&serveur, &arg);

  zs_dtor(&zs);
  arg_dtor(&arg);
  return (EXIT_SUCCESS);
}
