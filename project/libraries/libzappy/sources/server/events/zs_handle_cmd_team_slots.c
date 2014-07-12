/*
** zs_handle_cmd_team_slots.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Sun Jul 13 01:22:11 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_cmd_team_slots(t_zs *this, t_zc *zc,
					 unsigned int team_slots)
{
  t_zh		zh;

  zh = zc->hooks[ZHT_CMD_TEAM_SLOTS];
  if (zh.handler)
    zh.handler(this, zc, team_slots, zh.data);
  zs_handle_callback(this, ZHT_CMD_TEAM_SLOTS);
}
