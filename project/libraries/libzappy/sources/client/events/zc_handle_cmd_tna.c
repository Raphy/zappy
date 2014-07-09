/*
** zc_handle_cmd_tna.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Wed Jul  9 18:48:41 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_tna(t_zc *this, const char *tna)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_TNA];
  if (zh.handler)
    zh.handler(this, tna, zh.data);
  zc_handle_callback(this, ZHT_CMD_TNA);
}
