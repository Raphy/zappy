/*
** zc_handle_rmt_teams.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Mon Jul  7 10:29:00 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zc_handle_rmt_teams(t_zc *this, const char *teams)
{
  t_zh		zh;

  zh = this->hooks[ZHT_RMT_TEAMS];
  if (zh.handler)
    zh.handler(this, teams, zh.data);
  zc_handle_callback(this, ZHT_RMT_TEAMS);
}
