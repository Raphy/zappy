/*
** server_bct.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul 11 23:53:57 2014 damien sauvalle
** Last update Sat Jul 12 11:17:47 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"

void		server_bct(t_server *server, t_zc *zc,
			   t_zs *zs, t_position position)
{
  t_bct		bct;

  bct.position = position;
  bct.items = server->map[position.x][position.y].inventory;
  zs_send_cmd_bct(zs, zc, &bct);
}
