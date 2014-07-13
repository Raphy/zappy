/*
** set_client_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:46:18 2014 raphael defreitas
** Last update Tue Jul  1 01:15:32 2014 raphael defreitas
*/

#include	"handlers.h"
#include	"zappy.h"

void		set_client_handlers(t_zc *zc, void *data)
{
  printf("set client handler");
  
  zs_hook_cmd_left(zc, &handler_left, data);
  zs_hook_cmd_right(zc, &handler_right, data);
  zs_hook_cmd_forward(zc, &handler_forward, data);
  zs_hook_cmd_invocation(zc, &handler_incantation, data);
  zs_hook_cmd_look(zc, &handler_see, data);
  zs_hook_cmd_broadcast(zc, &handler_broadcast, data);
  
  /*
  zs_hook_cmd_expel(zc, &handler_expel, data);
  zs_hook_cmd_fork(zc, &handler_fork, data);
  zs_hook_cmd_inventory(zc, &handler_inventory, data);
  zs_hook_cmd_pick(zc, &handler_pick, data);
  zs_hook_cmd_put(zc, &handler_put, data);
  zs_hook_cmd_slot_number(zc, &handler_slot_number, data);
  */
}
