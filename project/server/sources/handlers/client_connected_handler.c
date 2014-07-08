/*
** client_connected_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Tue Jul  8 14:34:06 2014 damien sauvalle
*/

#include	<stdio.h>

#include        "handlers.h"
#include	"zappy.h"
#include	"player.h"
#include	"server.h"
#include	"bundle.h"

void		client_connected_handler(t_zs *zs, t_zc *zc, void *data)
{
  printf("Client connected (fd:%d)\n", zc->socket->fd);



  t_player player;
  /*
  **    Cree le jouer et crée un Bundle avc le joueur
  ** Le joueur doit setter son nom de team si il le fait pas Ko + Deco direct
  */
  /* Creation jouer */
  player_ctor(&player, data); /* en cas de FAil que faire ?*/

  /* affectation dans le server */
  add_player(data, &player);

  /*
    Faire un Bundle
   */

  set_client_handlers(zc, NULL);
  zs_send_welcome(zs, zc);
}
