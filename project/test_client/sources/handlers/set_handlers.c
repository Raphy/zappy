/*
** set_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:46:18 2014 raphael defreitas
** Last update Sun Jun 29 01:20:05 2014 raphael defreitas
*/

#include	"handlers.h"
#include	"zappy.h"

void		set_handlers(t_zc *zc, void *data)
{
  zc_hook_errno(zc, &errno_handler, data);
  zc_hook_callback(zc, &callback_handler, data);
  zc_set_timeout(zc, 2, 500);
  zc_hook_timeout(zc, &timeout_handler, data);
}
