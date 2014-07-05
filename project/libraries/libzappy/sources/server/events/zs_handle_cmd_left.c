/*
** zs_handle_cmd_right.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul  5 15:57:20 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_cmd_right(t_zs *this, t_zc *zc)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_RIGHT];
  if (zh.handler)
    zh.handler(this, zc, zh.data);
  zs_handle_callback(this, ZHT_CMD_RIGHT);
}
