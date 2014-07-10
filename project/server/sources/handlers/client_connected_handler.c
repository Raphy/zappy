/*
** client_connected_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Thu Jul 10 14:13:24 2014 damien sauvalle
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


  zs_hook_cmd_rmt(zc, &cmd_rmt_handler, data); /* creation rmt*/
  zs_hook_cmd_graphic(zc, &cmd_graphic_handler, data); /* creation graphic */
  zs_hook_cmd_team_name(zc, &cmd_team_name_handler, data); /* creation player */

  zs_send_welcome(zs, zc);
}
