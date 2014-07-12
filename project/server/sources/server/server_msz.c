/*
** server_msz.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 19:08:17 2014 damien sauvalle
** Last update Sat Jul 12 15:37:06 2014 damien sauvalle
*/

#include	<stdio.h>


#include	"zappy.h"
#include	"server.h"

void	server_msz(t_zs *zs, t_zc *zc, void *server)
{
  t_msz msz;

  msz.width = ((t_server *)server)->arg->x_world;
  msz.height = ((t_server *)server)->arg->y_world;
  zs_send_cmd_msz(zs, zc, &msz);
}
