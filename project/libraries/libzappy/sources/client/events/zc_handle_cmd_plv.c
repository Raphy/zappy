/*
** zc_handle_cmd_plv.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Thu Jul 10 03:30:57 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_plv(t_zc *this, t_plv *plv)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_PLV];
  if (zh.handler)
    zh.handler(this, plv, zh.data);
  zc_handle_callback(this, ZHT_CMD_PLV);
}
