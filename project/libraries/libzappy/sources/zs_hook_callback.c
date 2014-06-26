/*
** zs_hook_callback.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:53:22 2014 raphael defreitas
** Last update Thu Jun 26 11:55:43 2014 raphael defreitas
*/

#include	<stdlib.h>

#include	"zappy.h"

void		zs_hook_callback(t_zs *this, t_zsh_callback h, void *d)
{
  if (this == NULL)
    return ;
  zs_hook(this, ZHT_CALLBACK, h, d);
}
