/*
** zs_hook.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 10:26:38 2014 raphael defreitas
** Last update Thu May 15 10:46:35 2014 raphael defreitas
*/

#include	"zappy.h"

void		zs_hook(t_zs *this, t_zht type, void (*handler)(), void *data)
{
  if (type == ZHT_UNKNOWN || type == ZHT_MAX)
    return ;
  this->hooks[type].handler = handler;
  this->hooks[type].data = data;
}
