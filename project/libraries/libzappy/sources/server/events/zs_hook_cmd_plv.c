/*
** zs_hook_cmd_plv.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Thu Jul 10 02:09:17 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_hook_cmd_plv(t_zc *zc, t_zsh_uint_basic h, void *d)
{
  if (zc == NULL)
    return ;
  zc_hook(zc, ZHT_CMD_PLV, h, d);
}
