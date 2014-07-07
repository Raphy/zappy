/*
** zc_handle_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Mon Jul  7 18:02:41 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_bct(t_zc *this, t_bct *bct)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_BCT];
  if (zh.handler)
    zh.handler(this, bct, zh.data);
  zc_handle_callback(this, ZHT_CMD_BCT);
}
