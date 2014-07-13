/*
** server_mct.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sat Jul 12 11:12:30 2014 damien sauvalle
** Last update Sun Jul 13 09:48:28 2014 damien sauvalle
*/

#include	"zappy.h"
#include	"server.h"

void	server_mct(t_zs *zs, t_zc *zc, void *server)
{
  t_position position;

  position.y = 0;
  while (position.y < ((t_server *)server)->arg->y_world)
    {
      position.x = 0;
      while (position.x < ((t_server *)server)->arg->x_world)
	{
	  printf("mct : %d -- %d\n", position.y, position.x);
	  server_bct(zs, zc, &position, server);
	  position.x++;
	}
      position.y++;
    }
}
