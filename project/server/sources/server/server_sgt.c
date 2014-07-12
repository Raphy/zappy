/*
** server_sgt.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul 11 23:49:40 2014 damien sauvalle
** Last update Fri Jul 11 23:53:17 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"

void	server_sgt(t_server *server, t_zc *zc, t_zs *zs)
{
  zs_send_cmd_sgt(zs, zc, server->arg->time);
}
