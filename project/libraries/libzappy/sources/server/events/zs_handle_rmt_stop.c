/*
** zs_handle_rmt_stop.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Tue Jul  1 16:07:23 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_rmt_stop(t_zs *this, t_zc *zc)
{
  t_zh		zh;

  zh = zc->hooks[ZHT_RMT_STOP];
  if (zh.handler)
    zh.handler(this, zc, zh.data);
  zs_handle_callback(this, ZHT_RMT_STOP);
}
