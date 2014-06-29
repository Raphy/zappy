/*
** zs_handle_cmd_team_name.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sun Jun 29 03:54:25 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_cmd_team_name(t_zs *this, t_zc *zc, const char *tn)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_TEAM_NAME];
  if (zh.handler)
    zh.handler(this, zc, tn, zh.data);
  zs_handle_callback(this, ZHT_CMD_TEAM_NAME);
}
