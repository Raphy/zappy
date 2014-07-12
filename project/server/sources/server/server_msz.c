/*
** server_msz.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul 10 19:08:17 2014 damien sauvalle
** Last update Fri Jul 11 23:40:46 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"server.h"

void	server_msz(t_server *server, t_zc *zc, t_zs *zs)
{
  t_msz msz;

  msz.width = server->arg->x_world;
  msz.height = server->arg->y_world;
  zs_send_cmd_msz(zs, zc, &msz);
}
