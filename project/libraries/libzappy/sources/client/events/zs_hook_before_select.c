/*
** zc_hook_before_select.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Fri Jul  4 18:30:13 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_hook_before_select(t_zc *this, t_zch_basic h, void *d)
{
  if (this == NULL)
    return ;
  zc_hook(this, ZHT_BEFORE_SELECT, h, d);
}
