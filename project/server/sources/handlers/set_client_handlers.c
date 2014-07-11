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
}
