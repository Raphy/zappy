/*
** zc_hook_errno.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Fri Jun 27 13:57:12 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

void		zc_hook_errno(t_zc *this, t_zch_errno h, void *d)
{
  if (this == NULL)
    return ;
  zc_hook(this, ZHT_ERRNO, h, d);
}
