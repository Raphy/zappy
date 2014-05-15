/*
** zs_handle_timeout.c for zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu May 15 11:11:53 2014 raphael defreitas
** Last update Thu May 15 11:15:04 2014 raphael defreitas
*/

#include	"zappy.h"

void		zs_handle_timeout(t_zs *this)
{
  void		*data;
  void		(*handler)();

  handler = this->hooks[ZHT_TIMEOUT].handler;
  data = this->hooks[ZHT_TIMEOUT].data;
  if (handler)
    handler(this, data);
}
