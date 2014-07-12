/*
** zc_handle_cmd_enw.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 13:07:27 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_enw(t_zc *this, t_enw *enw)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_ENW];
  if (zh.handler)
    zh.handler(this, enw, zh.data);
  zc_handle_callback(this, ZHT_CMD_ENW);
}
