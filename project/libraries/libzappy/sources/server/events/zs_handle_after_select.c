/*
** zs_handle_after_select.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Fri Jul  4 18:25:02 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_after_select(t_zs *this)
{
  t_zh		zh;

  zh = this->hooks[ZHT_AFTER_SELECT];
  if (zh.handler)
    zh.handler(this, zh.data);
  zs_handle_callback(this, ZHT_AFTER_SELECT);
}
