/*
** set_server_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 19:46:18 2014 raphael defreitas
** Last update Thu Jul 10 01:00:35 2014 damien sauvalle
*/

#include	"handlers.h"
#include	"zappy.h"
#include        "server.h"

void		set_server_handlers(t_zs *zs, t_server *server)
{
  zs_hook_errno(zs, &errno_handler, server);
  zs_hook_callback(zs, &callback_handler, server);
  zs_set_timeout(zs, 2, 500);
  zs_hook_timeout(zs, &timeout_handler, server);

  zs_hook_client_connected(zs, &client_connected_handler, server);

  zs_hook_client_disconnected(zs, &client_disconnected_handler, server);

  /*  zs_hook_before_select(zs, &handler_before_select, server);
   */
}
