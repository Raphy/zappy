/*
** main.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 18:03:14 2014 raphael defreitas
** Last update Thu Jul 10 05:18:45 2014 raphael defreitas
*/

#include	<errno.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"remote.h"
#include	"zappy.h"

static void	kikoo_header(void)
{
  printf("  ______                           _____                      _\n");
  printf(" |___  /                          |  __ \\                    | |\n");
  printf("    / / __ _ _ __  _ __  _   _    | |__) |___ _ __ ___   ___ | |_");
  printf("___\n");
  printf("   / / / _` | '_ \\| '_ \\| | | |   |  _  // _ \\ '_ ` _ \\ / _ \\| ");
  printf(" __/ _ \\\n");
  printf("  / /_| (_| | |_) | |_) | |_| |   | | \\ \\  __/ | | | | | (_) | ||");
  printf("   __/\n");
  printf(" /_____\\__,_| .__/| .__/ \\__, |   |_|  \\_\\___|_| |_| |_|\\___/ ");
  printf(" \\__\\___|\n");
  printf("            | |   | |     __/ |\n");
  printf("            |_|   |_|    |___/\n");
  printf("\n\n");
}

static int	init_zappy(t_zc *zc, char *host, int port)
{
  if (zc_ctor(zc) == RET_FAILURE)
    {
      fprintf(stderr, "Initialization failed: %s\n",
	      errno == 0 ? "Unknown error" : strerror(errno));
      return (RET_FAILURE);
    }
  printf("Connecting to %s %d...\n", host, port);
  if (zc_connect(zc, host, port) == RET_FAILURE)
    {
      printf("Connection failed!\n");
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

static int	init_remote(t_remote *remote, t_zc *zc)
{
  if (remote_ctor(remote, zc) == RET_FAILURE)
    return (RET_FAILURE);
  remote_set_handlers(remote);
  return (RET_SUCCESS);
}

int		main(int argc, char **argv)
{
  t_zc		zc;
  t_remote	remote;

  kikoo_header();
  if (argc != 3)
    exit(printf("Usage: %s [host] [port]\n", argv[0]));
  if (init_zappy(&zc, argv[1], atoi(argv[2])) == RET_FAILURE ||
      init_remote(&remote, &zc) == RET_FAILURE)
    {
      remote_dtor(&remote);
      zc_dtor(&zc);
      return (EXIT_FAILURE);
    }
  zc_main(&zc);
  zc_dtor(&zc);
  remote_dtor(&remote);
  return (EXIT_SUCCESS);
}
