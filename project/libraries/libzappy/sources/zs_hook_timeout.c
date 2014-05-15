/*
** zs_hook_timeout.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:27:55 2014 raphael defreitas
** Last update Thu May 15 11:07:02 2014 raphael defreitas
*/

#include	"zappy.h"

void		zs_hook_timeout(t_zs *this, t_zsh_timeout h, void *d)
{
  zs_hook(this, ZHT_TIMEOUT, h, d);
}
