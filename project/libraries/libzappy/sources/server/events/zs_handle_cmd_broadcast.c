/*
** zs_handle_cmd_broadcast.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 19:23:58 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_cmd_broadcast(t_zs *this, t_zc *zc, const char *msg)
{
  t_zh		zh;

  zh = zc->hooks[ZHT_CMD_BROADCAST];
  if (zh.handler)
    zh.handler(this, zc, msg, zh.data);
  zs_handle_callback(this, ZHT_CMD_BROADCAST);
}
