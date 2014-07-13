/*
** cmd_graphic_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sat Jul 12 22:08:33 2014 damien sauvalle
*/

#include	<stdio.h>
#include	"server.h"
#include	"zappy.h"
#include	"player.h"

static void	set_hook(t_zc *zc, void *data)
{
  zs_hook_cmd_msz(zc, &server_msz, data);
  zs_hook_cmd_bct(zc, &server_bct, data);
  zs_hook_cmd_mct(zc, &server_mct, data);
  zs_hook_cmd_tna(zc, &server_tna, data);
  zs_hook_cmd_ppo(zc, &server_ppo, data);
  zs_hook_cmd_plv(zc, &server_plv, data);
  zs_hook_cmd_pin(zc, &server_pin, data);
  zs_hook_cmd_sst(zc, &server_sst, data);
  zs_hook_cmd_sgt(zc, &server_sgt, data);
}

static void	send_all_players(t_zs *zs, t_zc *zc , void *data)
{
  t_iterator	it;
  t_player	*player;

  iterator_ctor(&it, ((t_server *)data)->players, IT_DATA);
  while ((player = iterator_current(&it)))
    {
      server_pnw(zs, zc, player);
      server_pin(zs, zc, zc_get_uid(player->zc), data);
      iterator_next(&it);
    }
}

static void	first_send(t_zs *zs, t_zc *zc, void *data)
{
  server_msz(zs, zc, data);
  server_sgt(zs, zc, data);
  server_mct(zs, zc, data);
  server_tna(zs, zc, data);
  send_all_players(zs, zc, data);

  /*
    add egg
   */
}

void		cmd_graphic_handler(t_zs *zs, t_zc *zc, void *data)
{
  t_graphic	*graphic;
  t_server	*server;

  if (zc_get_type(zc) != ZCT_UNKNOWN)
    {
      zc_disconnect(zc);
      return ;
    }
  printf("[%d] is graphic\n", zc->socket->fd);
  zc_set_type(zc, ZCT_GRAPHIC);
  set_hook(zc, data);
  server = (t_server *)data;
  if ((graphic = graphic_new(zc)) == NULL)
    return ;
  list_push(server->graphic, graphic);
  first_send(zs, zc, data);
}
