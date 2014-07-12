/*
** server_mct.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 11:12:30 2014 damien sauvalle
** Last update Sat Jul 12 11:15:55 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"server.h"

void	server_mct(t_server *server, t_zc *zc, t_zs *zs)
{
  t_position position;

  position.x = 0;
  while (position.x < server->arg->x_world)
    {
      position.y = 0;
      while (position.y < server->arg->y_world)
	{
	  server_bct(server, zc, zs, position);
	  position.y++;
	}
      position.x++;
    }
}
