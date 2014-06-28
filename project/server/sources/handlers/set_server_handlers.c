/*
** set_server_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:46:18 2014 raphael defreitas
** Last update Sat Jun 28 02:03:22 2014 raphael defreitas
*/

#include	"handlers.h"
#include	"zappy.h"

void		set_server_handlers(t_zs *zs, void *data)
{
  zs_hook_errno(zs, &errno_handler, data);
  zs_hook_callback(zs, &callback_handler, data);
  zs_set_timeout(zs, 2, 500);
  zs_hook_timeout(zs, &timeout_handler, data);
  zs_hook_client_connected(zs, &client_connected_handler, data);
  zs_hook_client_disconnected(zs, &client_disconnected_handler, data);
}
