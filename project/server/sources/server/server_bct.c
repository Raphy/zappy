/*
** server_bct.c for zappy in /home/damien/zappy/project/server/sources/handlers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Fri Jul 11 23:53:57 2014 damien sauvalle
** Last update Sun Jul 13 09:43:37 2014 damien sauvalle
*/

#include	"server.h"
#include	"zappy.h"

void		server_bct(t_zs *zs, t_zc *zc,
			   t_position *position, void *server)
{
  t_bct		bct;

  if ( ((*position).x < ((t_server *)server)->arg->x_world) &&
       ((*position).y < ((t_server *)server)->arg->y_world))
    {
      bct.position = *position;
      bct.items = ((t_server *)server)->map[position->y][position->x].inventory;
      zs_send_cmd_bct(zs, zc, &bct);
    }
  else
    zs_send_cmd_sbp(zs, zc);
}
