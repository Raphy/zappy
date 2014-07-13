/*
** server_sgt.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul 11 23:49:40 2014 damien sauvalle
** Last update Sat Jul 12 12:41:15 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"

void	server_sgt(t_zs *zs, t_zc* zc, void *server)
{
  zs_send_cmd_sgt(zs, zc, ((t_server *)server)->arg->time);
}
