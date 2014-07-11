/*
** zs_hook_cmd_pfk.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Fri Jul 11 19:50:03 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_hook_cmd_pfk(t_zc *zc, t_zsh_uint_basic h, void *d)
{
  if (zc == NULL)
    return ;
  zc_hook(zc, ZHT_CMD_PFK, h, d);
}
