/*
** cmd_graphic_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sat Jul 12 11:21:49 2014 damien sauvalle
*/

#include	<stdio.h>

#include	"server.h"
#include	"zappy.h"

void		cmd_graphic_handler(t_zs *zs, t_zc *zc, void *data)
{
  t_graphic *graphic;
  t_server *server;
  t_position position;

  printf("Graphic HANDLER\n");

  if (zc_get_type(zc) != ZCT_UNKNOWN)
    {
      zc_disconnect(zc);
      return ;
    }
  printf("[%d] is graphic\n", zc->socket->fd);
  zc_set_type(zc, ZCT_GRAPHIC);

  server = (t_server *)data;
  if ((graphic = graphic_new(zc)) == NULL)
    return ;
  list_push(server->graphic, graphic);

  /*
  server_msz(data, zc, zs);
  server_sgt(data, zc, zs);
  server_mct(data, zc, zs);
  server_tna(data, zc, zs);
  server_pnw(data, zc, zs);
  */

}
