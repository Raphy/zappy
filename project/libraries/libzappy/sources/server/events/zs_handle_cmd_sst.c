/*
** zs_handle_cmd_sst.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Thu Jun 26 11:36:48 2014 raphael defreitas
** Last update Thu Jul 10 03:45:45 2014 raphael defreitas
*/

#include	"zappy.h"
#include	"_zappy.h"

void		zs_handle_cmd_sst(t_zs *this, t_zc *zc, unsigned int time)
{
  t_zh		zh;

  zh = this->hooks[ZHT_CMD_SST];
  if (zh.handler)
    zh.handler(this, zc, time, zh.data);
  zs_handle_callback(this, ZHT_CMD_SST);
}