/*
** server_send_all_graphic.c for zappy in /home/damien/zappy/project/server/sources/server
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jul 13 00:59:35 2014 damien sauvalle
** Last update Sun Jul 13 01:22:23 2014 damien sauvalle
*/

#include	"bundle.h"
#include	"server.h"
#include	"zappy.h"

void		server_send_ppo_all_graphic(t_bundle *bundle)
{
  t_server	*server;
  t_graphic	*graphic;
  t_iterator	it;

  server = bundle->server;
  iterator_ctor(&it, server->graphic, IT_DATA);
  while ((graphic = iterator_current(&it)))
    {
      server_ppo(server->zs, graphic->zc, zc_get_uid(bundle->player->zc), server);
      iterator_next(&it);
    }
}
