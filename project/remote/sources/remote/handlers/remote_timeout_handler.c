/*
** remote_timeout_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Wed Jul  2 04:16:40 2014 raphael defreitas
*/

#include	<stdio.h>

#include	"remote.h"
#include	"zappy.h"

void		remote_timeout_handler(t_zc *zc,
				       void *data)
{
  t_remote	*remote;

  remote = (t_remote *)data;
  printf("Timeout\n");
  zc_disable_timeout(zc);
  printf("zappy > ");
  fflush(stdout);
  zc_hook_stdin(zc, &remote_stdin_handler, data);
}
