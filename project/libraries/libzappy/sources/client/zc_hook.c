/*
** zc_hook.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:32:03 2014 raphael defreitas
** Last update Thu Jun 26 13:29:24 2014 raphael defreitas
*/

#include	"zappy.h"

void		zc_hook(t_zc *this, t_zht type, void (*handler)(), void *data)
{
  if (this == NULL || type == ZHT_UNKNOWN || type == ZHT_MAX)
    return ;
  this->hooks[type].handler = handler;
  this->hooks[type].data = data;
}
