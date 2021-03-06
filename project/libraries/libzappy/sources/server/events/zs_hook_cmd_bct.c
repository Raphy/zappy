/*
** zs_hook_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Sat Jul  5 16:36:59 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_hook_cmd_bct(t_zc *zc, t_zsh_cmd_bct h, void *d)
{
  if (zc == NULL)
    return ;
  zc_hook(zc, ZHT_CMD_BCT, h, d);
}
