/*
** set_client_handlers.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:46:18 2014 raphael defreitas
** Last update Sun Jun 29 18:56:03 2014 raphael defreitas
*/

#include	"handlers.h"
#include	"zappy.h"

void		set_client_handlers(t_zc *zc, void *data)
{
  zs_hook_cmd_unknown(zc, &cmd_unknown_handler, data);
  zs_hook_cmd_team_name(zc, &cmd_team_name_handler, data);
  zs_hook_cmd_graphic(zc, &cmd_graphic_handler, data);
  zs_hook_cmd_remote(zc, &cmd_remote_handler, data);
}
