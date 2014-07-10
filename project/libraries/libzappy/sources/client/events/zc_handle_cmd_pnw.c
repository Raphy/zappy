/*
** zc_handle_cmd_pnw.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Thu Jul 10 03:30:43 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_pnw(t_zc *this, t_pnw *pnw)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_PNW];
  if (zh.handler)
    zh.handler(this, pnw, zh.data);
  zc_handle_callback(this, ZHT_CMD_PNW);
}
