/*
** cmd_team_name_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Sat Jul 12 01:37:31 2014 damien sauvalle
*/

#include	<stdio.h>

#include	"zappy.h"
#include	"server.h"
#include	"player.h"
#include "handlers.h"
#include	"bundle.h"

void		cmd_team_name_handler(__attribute__((unused))t_zs *zs,
        t_zc *zc, const char *team_name, void *data)
{
  t_bundle      *bundle;
  t_server      *server;

  printf("TEAM NAME HANDLER\n");
  server = (t_server*) data;
  if (zc_get_type(zc) != ZCT_UNKNOWN)
    {
      zc_disconnect(zc);
      return ;
    }
  printf("[%d] is player. Team: %s\n", zc->socket->fd, team_name);
  zc_set_type(zc, ZCT_PLAYER);
  /*
    Creation du Player ici
   */
  t_player *player;

  player = player_new(data, zc, team_name);
  bundle = malloc(sizeof(*bundle));
  bundle->server = server;
  bundle->player = player;
  set_client_handlers(zc, bundle);

  /*if (player == NULL)
    disconnect client
  */
  list_push(server->players, player);


}
