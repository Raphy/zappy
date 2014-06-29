/*
** zs_handle_cmd_unknown.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sun Jun 29 18:51:19 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_cmd_unknown(t_zs *this, t_zc *zc, const char *cmd)
{
  t_zh		zh;

  zh = zc->hooks[ZHT_CMD_UNKNOWN];
  if (zh.handler)
    zh.handler(this, zc, cmd, zh.data);
  zs_handle_callback(this, ZHT_CMD_UNKNOWN);
}
