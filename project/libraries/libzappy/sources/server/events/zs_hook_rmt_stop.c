/*
** zs_hook_rmt_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources/server/events
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Tue Jul  1 16:05:38 2014 raphael defreitas
** Last update Tue Jul  1 16:06:26 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zs_hook_rmt_stop(t_zc *zc, t_zsh_client_basic h, void *d)
{
  if (zc == NULL)
    return ;
  zc_hook(zc, ZHT_RMT_STOP, h, d);
}
