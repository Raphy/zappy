/*
** zs_hook_timeout.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Thu Jun 26 11:54:37 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zs_hook_timeout(t_zs *this, t_zsh_timeout h, void *d)
{
  if (this == NULL)
    return ;
  zs_hook(this, ZHT_TIMEOUT, h, d);
}
