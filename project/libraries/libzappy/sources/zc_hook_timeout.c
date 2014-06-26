/*
** zc_hook_timeout.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Thu Jun 26 13:30:45 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zc_hook_timeout(t_zc *this, t_zch_timeout h, void *d)
{
  if (this == NULL)
    return ;
  zc_hook(this, ZHT_TIMEOUT, h, d);
}
