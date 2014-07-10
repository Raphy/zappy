/*
** zc_handle_cmd_sgt.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Thu Jul 10 03:42:13 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_sgt(t_zc *this, unsigned int uid)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_SGT];
  if (zh.handler)
    zh.handler(this, uid, zh.data);
  zc_handle_callback(this, ZHT_CMD_SGT);
}
