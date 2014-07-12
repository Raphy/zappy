/*
** zc_handle_cmd_seg.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sat Jul 12 18:37:15 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_cmd_seg(t_zc *this, const char *team_name)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_SEG];
  if (zh.handler)
    zh.handler(this, team_name, zh.data);
  zc_handle_callback(this, ZHT_CMD_SEG);
}
